/* $Header: mach3.c, v2.0 23-Feb-89 AJM */

0,		COND,		0x00000000,	".EQ",
0,		COND,		0x10000000,	".NE",
0,		COND,		0x20000000,	".CS",
0,		COND,		0x20000000,	".HS",
0,		COND,		0x30000000,	".CC",
0,		COND,		0x30000000,	".LO",
0,		COND,		0x40000000,	".MI",
0,		COND,		0x50000000,	".PL",
0,		COND,		0x60000000,	".VS",
0,		COND,		0x70000000,	".VC",
0,		COND,		0x80000000,	".HI",
0,		COND,		0x90000000,	".LS",
0,		COND,		0xA0000000,	".GE",
0,		COND,		0xB0000000,	".LT",
0,		COND,		0xC0000000,	".GT",
0,		COND,		0xD0000000,	".LE",
0,		COND,		0xE0000000,	".AL",
0,		COND,		0xF0000000,	".NV",

0,		LINK,		0x01000000,	".L",

0,		BRANCH,		0x0A000000,	"BEQ",
0,		BRANCH,		0x1A000000,	"BNE",
0,		BRANCH,		0x2A000000,	"BCS",
0,		BRANCH,		0x2A000000,	"BHS",
0,		BRANCH,		0x3A000000,	"BCC",
0,		BRANCH,		0x3A000000,	"BLO",
0,		BRANCH,		0x4A000000,	"BMI",
0,		BRANCH,		0x5A000000,	"BPL",
0,		BRANCH,		0x6A000000,	"BVS",
0,		BRANCH,		0x7A000000,	"BVC",
0,		BRANCH,		0x8A000000,	"BHI",
0,		BRANCH,		0x9A000000,	"BLS",
0,		BRANCH,		0xAA000000,	"BGE",
0,		BRANCH,		0xBA000000,	"BLT",
0,		BRANCH,		0xCA000000,	"BGT",
0,		BRANCH,		0xDA000000,	"BLE",
0,		BRANCH,		0xEA000000,	"BAL",
0,		BRANCH,		0xFA000000,	"BNV",

0,		DATA1,		ADC,	"ADC",
0,		DATA1,		ADD,	"ADD",
0,		DATA1,		AND,	"AND",
0,		DATA1,		BIC,	"BIC",
0,		DATA1,		EOR,	"EOR",
0,		DATA1,		ORR,	"ORR",
0,		DATA1,		RSB,	"RSB",
0,		DATA1,		RSC,	"RSC",
0,		DATA1,		SBC,	"SBC",
0,		DATA1,		SUB,	"SUB",
0,		DATA2,		MOV,	"MOV",
0,		DATA2,		MVN,	"MVN",
0,		DATA3,		CMN,	"CMN",
0,		DATA3,		CMP,	"CMP",
0,		DATA3,		TEQ,	"TEQ",
0,		DATA3,		TST,	"TST",

0,		SET,		0x00100000,	".S",

0,		PEE,		0x0010F000,	".P",

0,		REG,		0,		"R0",
0,		REG,		1,		"R1",
0,		REG,		2,		"R2",
0,		REG,		3,		"R3",
0,		REG,		4,		"R4",
0,		REG,		5,		"R5",
0,		REG,		6,		"R6",
0,		REG,		7,		"R7",
0,		REG,		8,		"R8",
0,		REG,		9,		"R9",
0,		REG,		10,		"R10",
0,		REG,		11,		"R11",
0,		REG,		12,		"R12",
0,		REG,		13,		"R13",
0,		REG,		14,		"R14",
0,		REG,		15,		"R15",
0,		REG,		15,		"PC",

0,		SHIFT,		0x00000000,	"LSL",
0,		SHIFT,		0x00000000,	"ASL",
0,		SHIFT,		0x00000020,	"LSR",
0,		SHIFT,		0x00000040,	"ASR",
0,		SHIFT,		0x00000060,	"ROR",

0,		RRX,		0x00000060,	"RRX",

0,		SDT,		0x04100000,	"LDR",
0,		SDT,		0x04000000,	"STR",

0,		BYTE,		0x00400000,	".B",

0,		TRANS,		0x00200000,	".T",

0,		BDT,		0x09100000,	"LDMDB",
0,		BDT,		0x08100000,	"LDMDA",
0,		BDT,		0x09900000,	"LDMIB",
0,		BDT,		0x08900000,	"LDMIA",
0,		BDT,		0x08900000,	"LDMFD",
0,		BDT,		0x08100000,	"LDMFA",
0,		BDT,		0x09900000,	"LDMED",
0,		BDT,		0x09100000,	"LDMEA",
0,		BDT,		0x09000000,	"STMDB",
0,		BDT,		0x08000000,	"STMDA",
0,		BDT,		0x09800000,	"STMIB",
0,		BDT,		0x08800000,	"STMIA",
0,		BDT,		0x09000000,	"STMFD",
0,		BDT,		0x09800000,	"STMFA",
0,		BDT,		0x08000000,	"STMED",
0,		BDT,		0x08800000,	"STMEA",

0,		SWI,		0x0F000000,	"SWI",

0,		ADR,		0x00000000,	"ADR",

0,		MUL,		0x00000090,	"MUL",
0,		MLA,		0x00200090,	"MLA",


