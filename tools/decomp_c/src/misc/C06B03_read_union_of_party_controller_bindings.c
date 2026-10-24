#include "som_c.h"

/* C06B03 read_union_of_party_controller_bindings   [class A, 7 bytes, 4 instructions]
 * Source: src/rom/read_union_of_party_controller_bindings.s
 * Documented in docs/event-menu-actor-cycle.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void read_union_of_party_controller_bindings(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    SET_A8(r, RAM8(0x00D9) | RAM8(0x00DA) | RAM8(0x00DB));
    RETURN_RTS(c);
}
SOM_REGISTER(0xC06B03, SOM_RTS, "gen", read_union_of_party_controller_bindings, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 1, 7, 4)
