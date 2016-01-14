/*
 * FTPDef.h
 *
 *  Created on: 2016年1月14日
 *      Author: nemochen
 */

#ifndef SRC_FTPCORE_FTPDEF_H_
#define SRC_FTPCORE_FTPDEF_H_

#include <iostream>
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
		virtual ~FTPInfo() = default;

		virtual void show()=0;
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

		void show()
		{
			cout << "name = " 				<< name 				<< endl;
			cout << "localPath = " 			<< localPath			<< endl;
			cout << "remoteUploadPath = " 	<< remoteUploadPath 	<< endl;
			cout << "successFolderPath = " 	<< successFolderPath 	<< endl;
		}
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

		void show()
		{
			cout << "name = " 				<< name 				<< endl;
			cout << "remoteDownloadPath = " 	<< remoteDownloadPath	<< endl;
			cout << "localPath = " 			<< localPath 			<< endl;
		}
	};

	struct ConnectInfo
	{
		ConnectInfo(string IP, string name, string password)
		:serverIP(IP), loginName(name), loginPassword(password)
		{
		}
		~ConnectInfo() = default;

		ConnectInfo & operator=(const ConnectInfo &right);

		void show()
		{
			cout << "serverIP = "		<< serverIP 		<< endl;
			cout << "loginName = "		<< loginName 		<< endl;
			cout << "loginPassword = "	<< loginPassword 	<< endl;
		}

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

		///	Show member information.
		void show();
	};
}




#endif /* SRC_FTPCORE_FTPDEF_H_ */
