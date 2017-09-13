#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "common.h"


_Bool InterpLoad(char *program);
_Bool InterpStep();
_Bool InterpRun();
_Bool InterpSetProgramBp(uint32_t addr);
_Bool InterpUnsetProgramBp(uint32_t addr);
_Bool InterpGetMemory(uint32_t offset, uint32_t count, int8_t *dst);
_Bool InterpSetMemory(uint32_t offset, uint32_t count, int8_t *src);
uint32_t InterpGetIP();
_Bool InterpSetIP(uint32_t new_ip);
_Bool IsEndOfProgram();

#endif
