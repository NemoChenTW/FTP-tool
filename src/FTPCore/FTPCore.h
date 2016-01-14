/*
 * FTPCore.h
 *
 *  Created on: 2016年1月13日
 *      Author: nemo
 */

#ifndef SRC_FTPCORE_FTPCORE_H_
#define SRC_FTPCORE_FTPCORE_H_

#include <string>
#include <vector>
#include "FTPDef.h"

using namespace std;

using FTPDef::FTPAction;
class FTPCore {

private:
	vector <FTPAction> vector_FTPAction;

public:
	FTPCore();
	virtual ~FTPCore();

	///		Push FTPAction into vector.
	void addFTPAction(FTPAction ftpAction);

};

#endif /* SRC_FTPCORE_FTPCORE_H_ */
