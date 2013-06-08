/*
 * btCom.h
 *
 *  Created on: 06.05.2013
 *      Author: Sascha Steffen
 */

#ifndef BTCOM_H_
#define BTCOM_H_

#ifdef __cplusplus
extern "C"{
#endif
    #include <stdbool.h>
    //for error codes definiton refer to errno.h
    //or open: http://www.virtsync.com/c-error-codes-include-errno
    /**
     * \brief
     * Connects to a BT device using RFCOMM
     *
     * \param mac MAC-adress, of the device  (NXT) to be connected
     * \return true on success, else false
     */
    bool btConnect();

    /**
     * \brief
     *Close BT-connection
     *\return true on success, else false
     */
    bool btDisconnect();

    /**
     * \brief sends Data through BT-Interface
     *
     * \param chars to write
     * \return Number of chars written, -1 if not connected or on error.
     */
    int btWriteBytes(const char* data,  unsigned int len);

    /**
     * \brief Reads Data from BT-Connection. Maximum maxLen chars will be read.
     * 		  Note that Strings are not neccessarily null-terminated.
     * 		  This function will not block.
     * \return number of read chars; -1 if not connected or on error
     */
    int btReadBytes(char* data,  unsigned int maxLen);

    /**
     * \brief Reads input from BT-connection until first '\n'-character, or
     * until maxLen-1 chars (excluding '\n') were read. This function will block
     * until one of these conditions was reached.
     * '\n' will be removed.
     * The String will always be terminated with '\0'.
     * \return number of read chars; -1 if not connected, or on error
     */
    int btReadLine(char* data, unsigned int maxLen);

#ifdef __cplusplus
}
#endif
#endif /* BTCOM_H_ */
