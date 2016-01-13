/*
 * FTPCore.h
 *
 *  Created on: 2016年1月13日
 *      Author: nemo
 */

#ifndef SRC_FTPCORE_FTPCORE_H_
#define SRC_FTPCORE_FTPCORE_H_

#include <string>

using namespace std;

class FTPCore {
public:
	FTPCore();
	virtual ~FTPCore();

private:
	enum class FTPType
	{
		fileUpload,
		folderUpload,
		fileDownload,
		folderDownload
	};

	struct UploadInfo
	{
		UploadInfo(string name, string localPath,
				string remoteUploadPath, string successFolderPath)
		:name(name), localPath(localPath)
		, remoteUploadPath(remoteUploadPath), successFolderPath(successFolderPath)
		{
		}
		~UploadInfo() = default;

	private:
		string name;				///< Name of this upload setting.
		string localPath;			///< Local upload path (File or Folder according to the FTPType).
		string remoteUploadPath;	///< Remote server upload path.
		string successFolderPath;	///< Local folder path for storing success files.
	};

	struct DownloadInfo
	{
		DownloadInfo(string name, string remoteFolderPath, string localPath)
		:name(name), remoteFolderPath(remoteFolderPath),  localPath(localPath)
		 {
		 }
		~DownloadInfo() = default;

	private:
		string name;				///< Name of this download setting.
		string remoteFolderPath;	///< Remote server download path.
		string localPath;			///< Local download path.
	};

	struct ConnectInfo
	{
		ConnectInfo(string IP, string name, string password)
		:serverIP(IP), loginName(name), loginPassword(password)
		{
		}
		~ConnectInfo() = default;

	private:
		string serverIP;
		string loginName;
		string loginPassword;
	};
};

#endif /* SRC_FTPCORE_FTPCORE_H_ */
