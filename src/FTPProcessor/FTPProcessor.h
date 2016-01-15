/*
 * FTPProcessor.h
 *
 *  Created on: 2016年1月14日
 *      Author: nemochen
 */

#ifndef SRC_FTPPROCESSOR_FTPPROCESSOR_H_
#define SRC_FTPPROCESSOR_FTPPROCESSOR_H_

#include "FTPCore/FTPCore.h"
#include "Utility/Utility.h"

namespace FTPProcessor
{

class FTPProcessor {
public:
	FTPProcessor();
	virtual ~FTPProcessor();

	void process(FTPCore *ftp);
};

}
#endif /* SRC_FTPPROCESSOR_FTPPROCESSOR_H_ */
