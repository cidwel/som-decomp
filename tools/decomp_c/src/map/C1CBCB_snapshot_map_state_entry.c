#include "som_c.h"

/* C1CBCB snapshot_map_state_entry   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/snapshot_map_state_entry.s
 * Documented in docs/cutscene-engine.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABYCV.
 */
static void snapshot_map_state_entry(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0xCBCD, 0xC1CBEA); /* snapshot_map_scroll_and_actor_cache */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC1CBCB, SOM_RTL, "gen", snapshot_map_state_entry, 0, L_A | L_B | L_Y | L_C | L_V, 1, 1, 0, 4, 2)
