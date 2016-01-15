/*
 * FileUtils.cpp
 *
 *  Created on: 2016年1月15日
 *      Author: nemochen
 */

#include <FTPProcessor/Utility/FileUtils/FileUtils.h>

#include <dirent.h>
#include <fstream>
#include <iostream>

namespace FTPProcessor {
namespace Utility {
namespace FileUtils {

using namespace std;
	/**
	 * @brief	Create directory.
	 *
	 * @param 	dirPath		Input directory path.
	 *
	 * @return	True if directory create successful, false otherwise.
	 */
	bool createDir(const std::string dirPath)
	{
		if (!fileExist(dirPath.c_str()))
		{
			if (mkdir(dirPath.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) == -1)
				return false;
		}
		return true;
	}

	/**
	 * @brief	Create directories.
	 *
	 * @param 	dirPath		Input directories path.
	 *
	 * Create directories by using Linux command "mkdir -p".
	 */
	void createDirs(const string dirPath)
	{
		string cmd = "mkdir -p ";
		cmd.append(dirPath);
		system(cmd.c_str());
	}

	/**
	 * @brief	Copy file form source to destination.
	 *
	 * @param 	srcFilePath		Input source path.
	 * @param	destFilePath	Input destination path.
	 *
	 * @return	True if file copy successful, false otherwise.
	 */
	bool copyFile(const char* srcFilePath, const char* destFilePath)
	{
		if (!fileExist(srcFilePath))
			return false;

		std::ifstream src(srcFilePath,  std::ios::binary);
		std::ofstream dst(destFilePath, std::ios::binary);

		cout << "CopyFile successfully from " << srcFilePath << " ... " << destFilePath << endl;

		dst << src.rdbuf();
		return true;
	}


	/**
	 * @brief	Move file form source to destination.
	 *
	 * @param	srcFilePath
	 * @param	destFilePath
	 *
	 * @return	True if file move successful, false otherwise.
	 */
	bool moveFile(const char* srcFilePath, const char* destFilePath)
	{
		if (rename(srcFilePath, destFilePath) == 0)
		{
			cout << "Move file successfully from " << srcFilePath << " ... " << destFilePath << endl;
			return true;
		}
		else
		{
			cout << "Error move file from " << srcFilePath << " ... " << destFilePath << endl;
			return false;
		}
	}

	/**
	 * @brief	Remove file.
	 *
	 * @param 	filePath	Input file path.
	 *
	 * @return	True if file delete successful, false otherwise.
	 */
	bool removeFile(const char* filePath)
	{
		if (fileExist(filePath) && remove(filePath) != 0)
		{
			cout << "Error deleting file " << filePath << endl;
			return false;
		}
		else
		{
			cout << "File successfully deleted " << filePath << endl;
			return true;
		}
	}

	/**
	 * @brief	List directory files.
	 *
	 * @param	dirName		Input directory path.
	 * @param	files		Input file list container.
	 * @param	recursive	Recursive list flag (Like Linux "ls -R").
	 *
	 * @retval	0		Normal.
	 * @retval	errno	Error number of directory open failure.
	 */
	int listDirectory(string dirName, list<string> &files, bool recursive)
	{
		// Process directory path separator character '/'.
		if(dirName[dirName.length()-1] != '/')
			dirName.append("/");

		DIR *dp;
		struct dirent *dirp;
		if((dp =opendir(dirName.c_str())) == NULL)
		{
			cout << "Error (" << errno << ") opening" << dirName << endl;
			return errno;
		}

		while((dirp = readdir(dp)) != NULL)
		{
			//Don't process '..' and '.' directories
			if(dirp->d_name[0] == '.') continue;

			if(dirp->d_type == DT_REG)		// Regular file
				files.push_back(string(dirName + dirp->d_name));
			else if(dirp->d_type == DT_DIR)	// Directory
			{
				if(recursive)
					listDirectory(dirName + dirp->d_name + "/", files, recursive);
			}
		}
		closedir(dp);
		files.sort();

		return 0;
	}

} /* namespace FileUtils */
} /* namespace Utility */
} /* namespace FTPProcessor */
