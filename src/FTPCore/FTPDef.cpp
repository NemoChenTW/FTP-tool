/*
 * FTPDef.cpp
 *
 *  Created on: 2016年1月14日
 *      Author: nemochen
 */


#include "FTPDef.h"

namespace FTPDef
{
char* str_FTPType[] = {"fileUpload", "folderUpload", "fileDownload", "folderDownload"};

/**
 * @brief	Set FTP action result.
 *
 * @param	success		Input FTP action result.
 */
void FTPInfo::setFTPResult(bool result)
{
	FTPResult = result;
}

UploadInfo &UploadInfo::operator=(const UploadInfo &right)
{
	this->name 				= right.name;
	this->localPath 		= right.localPath;
	this->remoteUploadPath 	= right.remoteUploadPath;
	this->successFolderPath	= right.successFolderPath;

	return (*this);
}

DownloadInfo &DownloadInfo::operator=(const DownloadInfo &right)
{
	this->name 					= right.name;
	this->remoteDownloadPath 	= right.remoteDownloadPath;
	this->localPath 			= right.localPath;

	return (*this);
}

ConnectInfo & ConnectInfo::operator=(const ConnectInfo &right)
{
	this->serverIP 		= right.serverIP;
	this->loginName 	= right.loginName;
	this->loginPassword = right.loginPassword;

	return (*this);
}

FTPAction & FTPAction::operator=(const FTPAction &right)
{
	this->ftpType 		= right.ftpType;
	this->connectInfo 	= right.connectInfo;
	this->ftpInfo		= right.ftpInfo;

	return (*this);
}

/**
 * @brief	Show member information.
 */
void FTPAction::show()
{
	cout << "ftpType = " << str_FTPType[(int)ftpType] << endl;
	connectInfo.show();
	ftpInfo->show();
}
}
