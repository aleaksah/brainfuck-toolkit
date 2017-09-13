/**
\file
\brief Interpreter implementation
*/

#include "interpreter.h"

/**
\brief Code memory
\details Contains code, that can be executed.
*/
char *Program;

/**
\brief Instruction pointer
\details Points to the next instruction in code memory, where 0 - first instruction.
*/
uint32_t IP;

/**
\brief Load code
\details Loads passed string in code memory, without any checks.
\param[in] program String with code.
*/
_Bool InterpLoad(char *program)
{
	free(Program);
	Program = (char*)malloc(sizeof(char) * (strlen(program) + 1));
	if (!Program)
	{
		return false;
	}

	strcpy(Program, program);

	return true;
}

/**
\brief Make step
\details Makes one step and returns true if successful, or false if IP points to the end of program or breakpoint occurs.
If meet any non-defined characters - skips it.
For example, if code memory is "+> 73.<", and IP equals 1 (second symbol, '>'), then after calling this function it interprets '>' and set IP to 4 (fifth symbol, '.').
*/
_Bool InterpStep()
{

	return false;
}

/**
\brief Run code
\details Runs interpretation of code from IP to the end or breakpoint.
Returns true if run successful.
Returns false if no valid program present, IP at the end of program or breakpoint occurs.
*/
_Bool InterpRun()
{
	_Bool result;
	while (result = InterpStep());

	return result;
}

/**
\brief Set breakpoint
\details Sets breakpoint at the passed address. When IP points to the passed address - breakpoint occur.
Returns true, if breakpoint set successful, even if it already set.
Returns false, if passed address points outside the memory.
\param[in] addr address, where set breakpoint.
*/
_Bool InterpSetProgramBp(uint32_t addr)
{

	return false;
}

/**
\brief Removes breakpoint
\details Removes breakpoints and return true if breakpoint removed or not fount at the passed address, and returns false, if passed address points outside the memory.
\param[in] addr address, where remove breakpoint.
*/
_Bool InterpUnsetProgramBp(uint32_t addr)
{

	return false;
}

/**
\brief Dump data memory
\details Dumps data memory from passed offset to passed buffer, returns true if memory exists and dumped, otherwise returns false.
\param[in] offset offset in memory, where start.
\param[in] count how many bytes to copy.
\param[out] dst address, where to copy.
*/
_Bool InterpGetMemory(uint32_t offset, uint32_t count, int8_t *dst)
{

	return false;
}

/**
\brief Change data memory
\details Overwrites data memory from passed buffer, returns true if memory exists and copied, otherwise returns false.
\param[in] offset offset in memory, where start.
\param[in] count how many bytes to copy.
\param[in] src buffer, from bytes will be copied.
*/
_Bool InterpSetMemory(uint32_t offset, uint32_t count, int8_t *src)
{

	return false;
}

/**
\brief Returns IP
\details Returns current IP. IP always pointing to the next instruction.
*/
uint32_t InterpGetIP()
{
	return IP;
}

/**
\brief Sets IP
\details Sets IP and return true if IP set successful, or false if IP points out of code memory.
\param[in] new_ip value of IP to set.
*/
_Bool InterpSetIP(uint32_t new_ip)
{
	IP = new_ip;

	return true;
}

/**
\brief If program execution ended
\details Returns true, if IP points to the end of program, otherwise false.
Useful to test cause of stopped program: end of program or breakpoint.
*/
_Bool IsEndOfProgram()
{
	if (!Program)
	{
		return true;
	}

	if (Program[IP])
	{
		return false;
	}

	return true;
}
