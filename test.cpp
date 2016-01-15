/*
 * test.cpp
 *
 *  Created on: 2016年1月13日
 *      Author: nemo
 */

#include "libFTPTool.h"

#include <iostream>

using namespace std;
using namespace FTPDef;
using namespace FTPProcessor;
int main()
{
	cout << endl << "FTP-Tool Test." << endl;

	FTPCore ftp;

	ConnectInfo connectInfo("11.22.33.44", "sps", "abc123");
	UploadInfo uploadInfo("UD", "/media/data/UD/", "/home/sps/UD/", "/media/data/UD/BKP/");

	FTPAction ftpAct(FTPType::folderUpload, connectInfo, &uploadInfo);

	ftp.addFTPAction(ftpAct);
	ftp.processFTPAction();


	if (Utility::FileUtils::fileExist("/home/nemochen/workspace/FTP-tool/test.cpp"))
	{
		cout << "File Exit" << endl;
	}
	else
	{
		cout << "File Not Exit" << endl;
	}

	list<string> files;
	Utility::FileUtils::listDirectory("/home/nemochen/workspace/FTP-tool/", files ,true);
	for(auto i = files.begin(); i != files.end(); i++)
	{
		cout << (*i) << endl;
	}

	Utility::BashUtils::shellExecute("ls --color");

	cout << "End FTP-Tool Test." << endl << endl;
	return 0;
}



