/**
\file
\brief Interpreter implementation
\addtogroup Interpreter Brainfuck interpreter
@{
*/

#include "interpreter.h"

/**
\brief Size of data memory
\details Size of data memory to be allocated.
*/
#define DATA_MEMORY_SIZE (30000)

/**
\brief Code memory
\details Contains code, that can be executed.
*/
char *Program;

/**
\brief Code size
\details Size of code, updated with InterpLoad() function
*/
uint32_t ProgramLength;

/**
\brief Instruction pointer
\details Points to the next instruction in code memory, where 0 - first instruction.
*/
uint32_t IP;

/**
\brief Data memory
\details Data memory, initialized to zero at the startup.
*/
int8_t Memory[DATA_MEMORY_SIZE];

/**
\brief Data pointer
\details Points to the current cell in data memory, 0 at the startup.
*/
uint32_t DP;

/**
\brief Load code
\details Loads passed string in code memory, without any checks.
Returns true if loaded successfully, false otherwise.
\param[in] program String with code.
*/
_Bool InterpLoad(char *program)
{
	free(Program);
	ProgramLength = strlen(program);
	Program = (char*)malloc(sizeof(char) * (ProgramLength + 1));
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
For example, if code memory is "+> 73.<", and IP equals 1 (second symbol, '>'), then after calling this function it interprets '>' and set IP to 5 (sixth symbol, '.').
*/
_Bool InterpStep()
{
	uint32_t nested_cycles = 0;

	if (InterpIsEndOfProgram())
	{
		return false;
	}

	switch (Program[IP])
	{
		case '+':
			Memory[DP]++;
			IP++;
			break;

		case '-':
			Memory[DP]--;
			IP++;
			break;

		case '>':
			if ((DP + 1) < (DATA_MEMORY_SIZE - 1))
			{
				DP++;
			}
			IP++;
			break;

		case '<':
			if (DP > 0)
			{
				DP--;
			}
			IP++;
			break;

		case '.':
			putchar((int)Memory[DP]);
			IP++;
			break;

		case ',':
			Memory[DP] = (int8_t)getchar();
			IP++;
			break;

		case '[':
			if (Memory[DP])
			{
				IP++;
			}
			else
			{
				while (IP < ProgramLength)
				{
					IP++;

					if (Program[IP] == '[')
					{
						nested_cycles++;
					}

					if ((Program[IP] == ']') && (nested_cycles == 0))
					{
						IP++;
						break;
					}

					if ((Program[IP] == ']') && (nested_cycles))
					{
						nested_cycles--;
					}
				}
			}
			break;

		case ']':
			while (IP > 0)
			{
				IP--;

				if (Program[IP] == ']')
				{
					nested_cycles++;
				}

				if ((Program[IP] == '[') && (nested_cycles == 0))
				{
					break;
				}

				if ((Program[IP] == '[') && (nested_cycles))
				{
					nested_cycles--;
				}
			}
			break;
	}

	while ((Program[IP] != '\0') && (!strchr("+-<>[],.", Program[IP]))) IP++;

	return true;
}

/**
\brief Run code
\details Runs interpretation of code from IP to the end or breakpoint.
Returns true if run successful.
Returns false if no valid program present or breakpoint occurs.
*/
_Bool InterpRun()
{
	while (InterpStep());

	return InterpIsEndOfProgram();
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
	if (!Program)
	{
		return false;
	}

	if (IP <= ProgramLength)
	{
		IP = new_ip;
		return true;
	}
	
	return false;
}

/**
\brief Is program execution ended
\details Returns true, if IP points to the end of program, otherwise false.
Useful to test cause of stopped program: end of program or breakpoint.
*/
_Bool InterpIsEndOfProgram()
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
/**@}*/
