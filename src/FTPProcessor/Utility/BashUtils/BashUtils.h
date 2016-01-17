/*
 * BashUtils.h
 *
 *  Created on: 2016年1月15日
 *      Author: nemochen
 */

#ifndef SRC_FTPPROCESSOR_UTILITY_BASHUTILS_BASHUTILS_H_
#define SRC_FTPPROCESSOR_UTILITY_BASHUTILS_BASHUTILS_H_

#include <string>

namespace FTPProcessor {
namespace Utility {
namespace BashUtils {

///	Execute shell command.
bool shellExecute(const char* cmdString);

std::string getCmdOutput(const char* cmdString);

} /* namespace BashUtils */
} /* namespace Utility */
} /* namespace FTPProcessor */

#endif /* SRC_FTPPROCESSOR_UTILITY_BASHUTILS_BASHUTILS_H_ */
