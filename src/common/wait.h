/***********************************************************************************************************************************
Wait Handler
***********************************************************************************************************************************/
#ifndef COMMON_WAIT_H
#define COMMON_WAIT_H

/***********************************************************************************************************************************
Wait object
***********************************************************************************************************************************/
typedef struct Wait Wait;

/***********************************************************************************************************************************
Functions
***********************************************************************************************************************************/
Wait *waitNew(double waitTime);
bool waitMore(Wait *this);
void waitFree(Wait *this);

/***********************************************************************************************************************************
Macros for function logging
***********************************************************************************************************************************/
#define FUNCTION_DEBUG_WAIT_TYPE                                                                                                   \
    Wait *
#define FUNCTION_DEBUG_WAIT_FORMAT(value, buffer, bufferSize)                                                                      \
    objToLog(value, "Wait", buffer, bufferSize)

#endif
