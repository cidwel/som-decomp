#include "som_c.h"

/* C7D000 saved_flag_menu_exception_pha_asl_brk_prefix   [class A, 4 bytes, 3 instructions]
 * Source: src/rom/saved_flag_menu_exception_pha_asl_brk_prefix.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: BXY.
 */
static void saved_flag_menu_exception_pha_asl_brk_prefix(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    c->fail = 1; /* BRK: software interrupt, outside the contract (the oracle stops here as well) */
    return;
}
SOM_REGISTER(0xC7D000, SOM_RTL, "gen", saved_flag_menu_exception_pha_asl_brk_prefix, 0, L_B | L_X | L_Y, 1, 1, 0, 4, 3)
