/*
 * FTPCore.cpp
 *
 *  Created on: 2016年1月13日
 *      Author: nemo
 */

#include "FTPCore.h"

FTPCore::FTPCore()
{
	// TODO Auto-generated constructor stub

}

FTPCore::~FTPCore()
{
	// TODO Auto-generated destructor stub
}

void FTPCore::addFTPAction(FTPAction ftpAction)
{
	vector_FTPAction.push_back(ftpAction);
}


FTPCore::UploadInfo &FTPCore::UploadInfo::operator=(const UploadInfo &right)
{
	this->name 				= right.name;
	this->localPath 		= right.localPath;
	this->remoteUploadPath 	= right.remoteUploadPath;
	this->successFolderPath	= right.successFolderPath;

	return (*this);
}

FTPCore::DownloadInfo &FTPCore::DownloadInfo::operator=(const DownloadInfo &right)
{
	this->name 					= right.name;
	this->remoteDownloadPath 	= right.remoteDownloadPath;
	this->localPath 			= right.localPath;

	return (*this);
}

FTPCore::ConnectInfo & FTPCore::ConnectInfo::operator=(const ConnectInfo &right)
{
	this->serverIP 		= right.serverIP;
	this->loginName 	= right.loginName;
	this->loginPassword = right.loginPassword;

	return (*this);
}

FTPCore::FTPAction & FTPCore::FTPAction::operator=(const FTPAction &right)
{
	this->ftpType 		= right.ftpType;
	this->connectInfo 	= right.connectInfo;
	this->ftpInfo		= right.ftpInfo;

	return (*this);
}

