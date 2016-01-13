/*
 * FTPCore.h
 *
 *  Created on: 2016年1月13日
 *      Author: nemo
 */

#ifndef SRC_FTPCORE_FTPCORE_H_
#define SRC_FTPCORE_FTPCORE_H_

class FTPCore {
public:
	FTPCore();
	virtual ~FTPCore();

	enum class FTPType
	{
		fileUpload,
		folderUpload,
		fileDownload,
		folderDownload
	};

};

#endif /* SRC_FTPCORE_FTPCORE_H_ */
