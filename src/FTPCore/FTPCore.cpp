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

/**
 * @brief	Process FTPAction in the vector.
 */
void FTPCore::processFTPAction()
{
	for(auto i = vector_FTPAction.begin();
			i != vector_FTPAction.end(); i++)
	{
		(*i).show();
	}

}
