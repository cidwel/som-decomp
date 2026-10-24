#include "som_c.h"

/* C06E8D test_native_menu_ring_row_coordinates_for_visibility   [class B, 18 bytes, 10 instructions]
 * Source: src/rom/test_native_menu_ring_row_coordinates_for_visibility.s
 * Documented in docs/event-menu-ring-geometry.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: BXC.
 */
static void test_native_menu_ring_row_coordinates_for_visibility(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value;
    BUS16_OK(c, (uint16_t)(0x0002 + x), value);
    if (value >= 0x0100) {
        r->a = value;
        r->c = 1;
        RETURN_RTS(c);
    }
    uint16_t value2;
    BUS16_OK(c, (uint16_t)(0x0004 + x), value2);
    if (value2 >= 0xE8) {
        r->a = value2;
        r->c = 1;
        RETURN_RTS(c);
    }
    r->a = value2;
    r->c = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC06E8D, SOM_RTS, "hand", test_native_menu_ring_row_coordinates_for_visibility, 0, L_B | L_X | L_C, 1, 0, 0, 18, 10)
