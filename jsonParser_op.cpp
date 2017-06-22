#include <stdlib.h>
#include <unistd.h>
extern char ** environ;
#include "fcgio.h"
//#include <iostream> std::streambuf, std::cout
//#include <fstream>  std::ofstream
#include "fcgi_config.h"

using namespace std;

static const unsigned long STDIN_MAX = 1000000;

//打印系统或者http请求的环境变量
static void penv(const char * const *envp)
{
	cout << "<PRE>\n";
	for(; *envp; ++envp)
	{
		cout << *envp << "\n";
	}
	cout << "</PRE>\n";
}

static long gstdin(FCGX_Request *request, char **content)
{
    char *contentLength = FCGX_GetParam("CONTENT_LENGTH", request->envp);
    unsigned long len = STDIN_MAX;

    if(contentLength)
    {
        //for example 1000  300  error!
        len = strtol(contentLength, &contentLength, 10);
        if(*contentLength)
        {
            cerr << "can't parse \"CONTENT_LENGTH="
                 << FCGX_GetParam("CONTENT_LENGTH",request->envp)
                 << "\"\n";

            len = STDIN_MAX;
        }
        if(len > STDIN_MAX)
        {
            len = STDIN_MAX;
        }

        *content = new char [len];

        cin.read(*content, len);
        len = cin.gcount();
    }

    //when CONTENT_LENGTH is missing or unparsable
    else
    {
    	*content = 0;
    	len = 0;
    }

    //去除缓冲区中多余的内容
    //istream& ignore (streamsize n = 1, int delim = EOF);
    do 
    {
    	cin.ignore(1024);
    }while(cin.gcount() == 1024);

    return len;

}

int main(void)
{
	int count = 0;
	long pid = getpid();

	//保存原始cin的buf
	streambuf * cin_streambuf = cin.rdbuf();
	streambuf * cout_streambuf = cout.rdbuf();
	streambuf * cerr_streambuf = cerr.rdbuf();

	FCGX_Request request;
	FCGX_Init();
	FCGX_InitRequest(&request,0,0);

	while(FCGX_Accept_r(&request) == 0)
	{
		fcgi_streambuf cin_fcgi_streambuf(request.in);
		fcgi_streambuf cout_fcgi_streambuf(request.out);
		fcgi_streambuf cerr_fcgi_streambuf(request.err);

#if HAVE_IOSTREAM_WITHASSIGN_STREAMBUF
		cin = &cin_fcgi_streambuf;
		cout = &cout_fcgi_streambuf;
		cerr = &cerr_fcgi_streambuf;
#else
		cin.rdbuf(&cin_fcgi_streambuf);
		cout.rdbuf(&cout_fcgi_streambuf);
		cerr.rdbuf(&cerr_fcgi_streambuf);
#endif

		char * content = NULL;
		unsigned long clen = gstdin(&request, &content);

		cout << "<H4>Request Environment</H4>\n";
		penv(request.envp);

		cout << "<H4>Process/Initial Environment</H4>\n";
		penv(environ);

		cout << "<H4>Standard Input - </H4>" << clen;
		if(clen == STDIN_MAX) 
		{
			cout << " (STDIN_MAX)";
		}
		cout << " bytes</H4>\n";

		//jsonParser(content);

		//将content写入返回的cout_fcgi_streambuf中
		if(clen)
		{
			cout.write(content, clen);
		}

		if(content)
		{
			delete []content;
		}
	}
#if HAVE_IOSTREAM_WITHASSIGN_STREAMBUF
	cin = cin_streambuf;
	cout = cout_streambuf;
	cerr = cerr_streambuf;
#else
	cin.rdbuf(cin_streambuf);
	cout.rdbuf(cout_streambuf);
	cerr.rdbuf(cerr_streambuf);
#endif

	return 0;
}