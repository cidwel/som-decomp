#include "som_c.h"

/* C0709C add_native_menu_row_tile_segment_when_comparison_carries   [class A, 7 bytes, 4 instructions]
 * Source: src/rom/add_native_menu_row_tile_segment_when_comparison_carries.s
 * Documented in docs/event-menu-navigation-icons.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXY.
 */
static void add_native_menu_row_tile_segment_when_comparison_carries(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const bool carry = r->c;
    uint8_t a1;
    uint8_t a_hi1;
    if (!carry) {
        a1 = (uint8_t)a;
        a_hi1 = a >> 8;
    } else {
        a1 = (uint8_t)(a + 0x0200);
        a_hi1 = (uint16_t)(a + 0x0200) >> 8;
    }
    r->a = (a_hi1 << 8) | a1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0709C, SOM_RTS, "gen", add_native_menu_row_tile_segment_when_comparison_carries, 0, L_A | L_B | L_X | L_Y, 1, 0, 0, 7, 4)
