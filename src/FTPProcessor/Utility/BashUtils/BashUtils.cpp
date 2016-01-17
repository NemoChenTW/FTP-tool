/*
 * BashUtils.cpp
 *
 *  Created on: 2016年1月15日
 *      Author: nemochen
 */

#include <FTPProcessor/Utility/BashUtils/BashUtils.h>

#include <iostream>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

namespace FTPProcessor {
namespace Utility {
namespace BashUtils {

using namespace std;

#define MAX_PIPEBUF_SIZE	128

/**
 * execute shell command and check result valid
 */
/**
 * @brief	Execute shell command and check result valid.
 *
 * @param	cmdString	Input shell command.
 *
 * @return	Shell command execute result.
 */
bool shellExecute(const char* cmdString)
{
    if (NULL == cmdString) return false;

	int status = system(cmdString);
	if (status < 0)
	{
		cout << "Cmd: " << cmdString << "\t error: " << strerror(errno) << endl;
		return false;
	}

	if (WIFEXITED(status))			// 取得command執行結果
	{
		cout << "Normal termination, exit status = " << WEXITSTATUS(status) << endl;
	}
	else if (WIFSIGNALED(status))	// 如果command被信號中斷,取得信號值
	{
		cout << "Abnormal termination,signal number = " << WTERMSIG(status) << endl;
	}
	else if (WIFSTOPPED(status))	// 如果command被信號暫停執行,取得信號值
	{
		cout << "Process stopped, signal number = " << WSTOPSIG(status) << endl;
	}

	return true;
}


/**
 * Execute shell command and get output result
 */
string getCmdOutput(const char* cmdString)
{
    FILE* pipe = popen(cmdString, "r");
    if (!pipe) return "ERROR";

    char buffer[MAX_PIPEBUF_SIZE];
    std::string result("");
    while(!feof(pipe)) {
        if(fgets(buffer, MAX_PIPEBUF_SIZE, pipe) != NULL)
            result += buffer;
    }
    pclose(pipe);
    return result.substr(0, result.length()-1);
}

} /* namespace BashUtils */
} /* namespace Utility */
} /* namespace FTPProcessor */
