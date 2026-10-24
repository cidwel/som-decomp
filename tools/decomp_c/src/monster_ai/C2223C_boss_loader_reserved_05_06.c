#include "som_c.h"

/* C2223C boss_loader_reserved_05_06   [class A, 1 bytes, 1 instructions]
 * Source: src/rom/boss_loader_reserved_05_06.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void boss_loader_reserved_05_06(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2223C, SOM_RTS, "gen", boss_loader_reserved_05_06, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 1, 1)
