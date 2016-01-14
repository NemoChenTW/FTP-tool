/*
 * test.cpp
 *
 *  Created on: 2016年1月13日
 *      Author: nemo
 */

#include "libFTPTool.h"

#include <iostream>

using namespace std;

int main()
{
	cout << "FTP-Tool Test." << endl;

	FTPCore ftp;

	FTPCore::ConnectInfo connectInfo("11.22.33.44", "sps", "abc123");
	FTPCore::UploadInfo uploadInfo("UD", "/media/data/UD/", "/home/sps/UD/", "/media/data/UD/BKP/");

	FTPCore::FTPAction ftpAct(FTPCore::FTPType::folderUpload, connectInfo, &uploadInfo);

	ftp.addFTPAction(ftpAct);

	cout << "End FTP-Tool Test." << endl;
	return 0;
}



