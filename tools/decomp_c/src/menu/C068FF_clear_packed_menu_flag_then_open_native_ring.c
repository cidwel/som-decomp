#include "som_c.h"

/* C068FF clear_packed_menu_flag_then_open_native_ring   [class A, 21 bytes, 8 instructions]
 * Source: src/rom/clear_packed_menu_flag_then_open_native_ring.s
 * Documented in docs/event-menu-ring-waits.md
 * Entry: M=any X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void clear_packed_menu_flag_then_open_native_ring(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, -1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM8(0x1803) &= 0x7F;
    RAM16_SET(0x1812, 1);
    RAM16_SET(0x1814, 1);
    r->a = 1;
    r->z = 0;
    r->n = 0;
    r->mf = 0;
    TAIL_CALL(c, 0xC06F72, SOM_RTS); /* build_native_menu_ring_list_without_initial_category_step */
}
SOM_REGISTER(0xC068FF, SOM_RTS, "gen", clear_packed_menu_flag_then_open_native_ring, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, -1, 0, 21, 8)
