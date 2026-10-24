#include "som_c.h"

/* C0794A mark_selected_native_ring_row_and_return_owner_or_special_descriptor   [class A, 39 bytes, 22 instructions]
 * Source: src/rom/mark_selected_native_ring_row_and_return_owner_or_special_descriptor.s
 * Documented in docs/event-menu-action-rows.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void mark_selected_native_ring_row_and_return_owner_or_special_descriptor(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    uint8_t ring_cursor = RAM8(RING_CURSOR);
    RAM8(0x18C0 + (uint8_t)((a_hi << 8) | (uint8_t)(ring_cursor << 4))) |= 0x80;
    uint8_t value2 = RAM8(0x18A0 + (uint8_t)((a_hi << 8) | (uint8_t)(ring_cursor << 1)));
    uint8_t value3 = RAM8(0x1880 + (uint8_t)((a_hi << 8) | (uint8_t)(ring_cursor << 1)));
    uint8_t value4 = BUS8(c, 0xD8FF16);
    uint8_t y1;
    if (value3 != value4) {
        y1 = (uint8_t)((a_hi << 8) | (uint8_t)(value2 - 1));
    } else {
        y1 = 0xFE;
    }
    SET_A8(r, y1);
    r->x = (uint8_t)((a_hi << 8) | (uint8_t)(ring_cursor << 1));
    r->y = y1;
    r->c = value3 >= value4;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0794A, SOM_RTS, "gen", mark_selected_native_ring_row_and_return_owner_or_special_descriptor, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 39, 22)
