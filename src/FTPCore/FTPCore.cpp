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

/**
 * @brief	Push FTPAction into vector.
 *
 * @param 	ftpAction	Input FTPAction structure.
 */
void FTPCore::addFTPAction(FTPAction ftpAction)
{
	vector_FTPAction.push_back(ftpAction);
}

