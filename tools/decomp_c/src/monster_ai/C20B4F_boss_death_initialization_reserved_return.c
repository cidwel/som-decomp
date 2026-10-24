#include "som_c.h"

/* C20B4F boss_death_initialization_reserved_return   [class A, 1 bytes, 1 instructions]
 * Source: src/rom/boss_death_initialization_reserved_return.s
 * Documented in docs/boss-native-unrecovered-55.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: AYCV.
 */
static void boss_death_initialization_reserved_return(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC20B4F, SOM_RTS, "gen", boss_death_initialization_reserved_return, 0, L_A | L_Y | L_C | L_V, 1, 0, 0, 1, 1)
