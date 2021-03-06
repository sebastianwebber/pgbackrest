/***********************************************************************************************************************************
IO Write
***********************************************************************************************************************************/
#ifndef COMMON_IO_WRITE_H
#define COMMON_IO_WRITE_H

/***********************************************************************************************************************************
IO write object
***********************************************************************************************************************************/
typedef struct IoWrite IoWrite;

#include "common/io/filter/group.h"
#include "common/type/buffer.h"

/***********************************************************************************************************************************
Function pointer types
***********************************************************************************************************************************/
typedef void (*IoWriteOpen)(void *driver);
typedef void (*IoWriteProcess)(void *driver, const Buffer *buffer);
typedef void (*IoWriteClose)(void *driver);

/***********************************************************************************************************************************
Constructor
***********************************************************************************************************************************/
IoWrite *ioWriteNew(void *driver, IoWriteOpen open, IoWriteProcess write, IoWriteClose close);

/***********************************************************************************************************************************
Functions
***********************************************************************************************************************************/
void ioWriteOpen(IoWrite *this);
void ioWrite(IoWrite *this, const Buffer *buffer);
void ioWriteClose(IoWrite *this);

/***********************************************************************************************************************************
Getters/Setters
***********************************************************************************************************************************/
const IoFilterGroup *ioWriteFilterGroup(const IoWrite *this);
void ioWriteFilterGroupSet(IoWrite *this, IoFilterGroup *filterGroup);
size_t ioWriteSize(const IoWrite *this);

/***********************************************************************************************************************************
Macros for function logging
***********************************************************************************************************************************/
#define FUNCTION_DEBUG_IO_WRITE_TYPE                                                                                               \
    IoWrite *
#define FUNCTION_DEBUG_IO_WRITE_FORMAT(value, buffer, bufferSize)                                                                  \
    objToLog(value, "IoWrite", buffer, bufferSize)

#endif
