#include "som_c.h"

/* C06D37 choose_next_native_menu_ring_row_with_directional_wrap   [class A, 30 bytes, 17 instructions]
 * Source: src/rom/choose_next_native_menu_ring_row_with_directional_wrap.s
 * Documented in docs/event-menu-ring-geometry.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: ABY.
 */
static void choose_next_native_menu_ring_row_with_directional_wrap(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint8_t ring_cursor = RAM8(RING_CURSOR);
    uint8_t value = RAM8(0x1806);
    uint8_t x1;
    if (value & 0x80) {
        x1 = (uint8_t)(ring_cursor - 1);
    } else {
        x1 = (uint8_t)((uint8_t)(ring_cursor - 1) + 2);
    }
    uint8_t ring_entry_count = RAM8(RING_ENTRY_COUNT);
    uint8_t a2;
    if (x1 < ring_entry_count) {
        a2 = x1;
    } else {
        uint8_t a1;
        if (!((uint8_t)(x1 - ring_entry_count) & 0x80)) {
            a1 = 0;
        } else {
            a1 = (uint8_t)(ring_entry_count - 1);
        }
        a2 = a1;
    }
    SET_A8(r, a2);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC06D37, SOM_RTS, "gen", choose_next_native_menu_ring_row_with_directional_wrap, 0, L_A | L_B | L_Y, 1, 1, 1, 30, 17)
