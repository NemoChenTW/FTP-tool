/*
 * FileUtils.h
 *
 *  Created on: 2016年1月15日
 *      Author: nemochen
 */

#ifndef SRC_FTPPROCESSOR_UTILITY_FILEUTILS_FILEUTILS_H_
#define SRC_FTPPROCESSOR_UTILITY_FILEUTILS_FILEUTILS_H_

#include <string>
#include <sys/stat.h>

namespace FTPProcessor {
namespace Utility {
namespace FileUtlis {

	/**
	 * @brief	Check the file is exist or not.
	 *
	 * @param	filePath	Input file path
	 * .
	 * @return	True if the file is exist, false otherwise.
	 */
	inline bool fileExist(const char* filePath)
	{
		struct stat buf;
		int result = stat(filePath, &buf);

		return (result == 0);
	}

	///	Create directory.
    bool createDir(const std::string dirPath);

    ///	Create directories.
    void createDirs(const std::string dirPath);

    ///	Copy file form source to destination.
    bool copyFile(const char* srcFilePath, const char* destFilePath);

    ///	Move file form source to destination.
    bool moveFile(const char* srcFilePath, const char* destFilePath);

    ///	Remove file.
    bool removeFile(const char* filePath);

} /* namespace FileUtlis */
} /* namespace Utility */
} /* namespace FTPProcessor */

#endif /* SRC_FTPPROCESSOR_UTILITY_FILEUTILS_FILEUTILS_H_ */
