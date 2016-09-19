#ifndef MCG_H
#define MCG_H

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include "em_arith.h"
#include "em_label.h"
#include "em.h"
#include "em_comp.h"
#include "em_pseu.h"
#include "em_mnem.h"
#include "em_flag.h"
#include "em_ptyp.h"
#include "array.h"
#include "ir.h"

extern char em_pseu[][4];
extern char em_mnem[][4];
extern char em_flag[];

enum {
	SECTION_UNKNOWN = 0,
	SECTION_ROM,
	SECTION_DATA,
	SECTION_BSS,
	SECTION_TEXT
};

struct symbol
{
	const char* name;
	int section;
	bool is_defined : 1;
	bool is_exported : 1;
	bool is_proc : 1;
};

enum
{
    PARAM_NONE,
    PARAM_IVALUE,
    PARAM_LVALUE,
    PARAM_BVALUE,
};

struct insn
{
    int opcode;
    int paramtype;
    union {
        arith ivalue;
        struct {
            const char* label;
            arith offset;
        } lvalue;
        struct {
            struct basicblock* left;
            struct basicblock* right;
        } bvalue;
    } u;
};
    
struct procedure
{
    const char* name;
    struct basicblock* root_bb;
    size_t nlocals;
    ARRAY(struct basicblock, blocks);
};

struct basicblock
{
    const char* name;
    ARRAY(struct insn, insns);
    ARRAY(struct ir, irs);
    ARRAY(struct basicblock, inblocks);
    ARRAY(struct basicblock, outblocks);
    ARRAY(struct ir, outs);
    ARRAY(struct ir, ins);
    bool is_wired : 1;
    bool is_terminated : 1;
};

extern void fatal(const char* s, ...);
extern const char* aprintf(const char* fmt, ...);

extern void parse_em(void);

extern void symbol_init(void);
extern bool symbol_exists(const char* name);
extern struct symbol* symbol_get(const char* name);
extern void symbol_declare(const char* name, bool is_exported, bool is_proc);

extern void data_label(const char* name);
extern void data_int(arith data, size_t size, bool is_ro);
extern void data_block(const uint8_t* data, size_t size, bool is_ro);
extern void data_offset(const char* label, arith offset, bool is_ro);
extern void data_bss(arith size, int init);

extern void bb_init(void);
extern struct basicblock* bb_get(const char* name);
extern void bb_alias(struct basicblock* block, const char* name);
extern void bb_wire_outs_to_ins(struct basicblock* outblock, struct basicblock* inblock);

extern void tb_filestart(void);
extern void tb_fileend(void);
extern void tb_procedure(struct procedure* proc);
extern void tb_regvar(arith offset, int size, int type, int priority);

#endif

/* vim: set sw=4 ts=4 expandtab : */