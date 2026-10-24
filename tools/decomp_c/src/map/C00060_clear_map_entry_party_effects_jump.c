#include "som_c.h"

/* C00060 clear_map_entry_party_effects_jump   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/clear_map_entry_party_effects_jump.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void clear_map_entry_party_effects_jump(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC03848, SOM_RTL); /* clear_map_entry_party_effects_bridge */
}
SOM_REGISTER(0xC00060, SOM_RTL, "gen", clear_map_entry_party_effects_jump, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 1, 3, 1)
