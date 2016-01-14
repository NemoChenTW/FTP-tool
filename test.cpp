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
int main()
{
	cout << "FTP-Tool Test." << endl;

	FTPCore ftp;

	ConnectInfo connectInfo("11.22.33.44", "sps", "abc123");
	UploadInfo uploadInfo("UD", "/media/data/UD/", "/home/sps/UD/", "/media/data/UD/BKP/");

	FTPAction ftpAct(FTPType::folderUpload, connectInfo, &uploadInfo);

	ftp.addFTPAction(ftpAct);
	ftp.processFTPAction();

	cout << "End FTP-Tool Test." << endl;
	return 0;
}



