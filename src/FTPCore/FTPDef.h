/*
 * FTPDef.h
 *
 *  Created on: 2016年1月14日
 *      Author: nemochen
 */

#ifndef SRC_FTPCORE_FTPDEF_H_
#define SRC_FTPCORE_FTPDEF_H_

#include <string>
namespace FTPDef
{
using namespace std;
	enum class FTPType
	{
		fileUpload,
		folderUpload,
		fileDownload,
		folderDownload
	};

	class FTPInfo
	{
	public:
		FTPInfo() {};
		~FTPInfo() = default;
	};

	class UploadInfo :public FTPInfo
	{
	private:
		string name;				///< Name of this upload setting.
		string localPath;			///< Local upload path (File or Folder according to the FTPType).
		string remoteUploadPath;	///< Remote server upload path.
		string successFolderPath;	///< Local folder path for storing success files.

	public:
		UploadInfo(string name, string localPath,
				string remoteUploadPath, string successFolderPath)
		:name(name), localPath(localPath)
		, remoteUploadPath(remoteUploadPath), successFolderPath(successFolderPath)
		{
		}
		~UploadInfo() = default;

		UploadInfo & operator=(const UploadInfo &right);
	};

	class DownloadInfo :public FTPInfo
	{
	private:
		string name;				///< Name of this download setting.
		string remoteDownloadPath;	///< Remote server download path.
		string localPath;			///< Local download path.

	public:
		DownloadInfo(string name, string remoteDownloadPath, string localPath)
		:name(name), remoteDownloadPath(remoteDownloadPath),  localPath(localPath)
		 {
		 }
		~DownloadInfo() = default;

		DownloadInfo & operator=(const DownloadInfo &right);
	};

	struct ConnectInfo
	{
		ConnectInfo(string IP, string name, string password)
		:serverIP(IP), loginName(name), loginPassword(password)
		{
		}
		~ConnectInfo() = default;

		ConnectInfo & operator=(const ConnectInfo &right);

	private:
		string serverIP;
		string loginName;
		string loginPassword;
	};

	struct FTPAction
	{
		FTPAction(FTPType ftpType, ConnectInfo connectInfo, FTPInfo *ftpInfo)
		:ftpType(ftpType), connectInfo(connectInfo), ftpInfo(ftpInfo)
		{

		}
		FTPType 		ftpType;
		ConnectInfo		connectInfo;
		FTPInfo			*ftpInfo;

		FTPAction & operator=(const FTPAction &right);
	};


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
}




#endif /* SRC_FTPCORE_FTPDEF_H_ */
