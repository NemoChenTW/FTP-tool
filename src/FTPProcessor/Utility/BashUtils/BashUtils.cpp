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

/**
 * execute shell command and check result valid
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

} /* namespace BashUtils */
} /* namespace Utility */
} /* namespace FTPProcessor */
