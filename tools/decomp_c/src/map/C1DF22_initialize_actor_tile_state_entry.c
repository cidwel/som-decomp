#include "som_c.h"

/* C1DF22 initialize_actor_tile_state_entry   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/initialize_actor_tile_state_entry.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void initialize_actor_tile_state_entry(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0xDF24, 0xC1DF37); /* initialize_actor_tile_state */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC1DF22, SOM_RTL, "gen", initialize_actor_tile_state_entry, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 4, 2)
