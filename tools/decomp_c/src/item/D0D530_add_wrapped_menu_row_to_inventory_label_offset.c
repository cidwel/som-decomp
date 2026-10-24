#include "som_c.h"

/* D0D530 add_wrapped_menu_row_to_inventory_label_offset   [class B, 52 bytes, 27 instructions]
 * Source: src/rom/add_wrapped_menu_row_to_inventory_label_offset.s
 * Documented in docs/event-menu-text-tick.md
 * Entry: M=any X=any DB=$00 D=$0000.  Callers read: ABYV.
 */
static void add_wrapped_menu_row_to_inventory_label_offset(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, -1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    uint8_t value = RAM8(0x1847);
    uint8_t a1;
    uint8_t a_hi1;
    if (value != 2) {
        uint8_t ring_cursor = RAM8(RING_CURSOR);
        uint8_t value2 = RAM8(0x182E);
        uint8_t ring_entry_count = RAM8(RING_ENTRY_COUNT);
        uint8_t x2;
        if ((uint8_t)((uint8_t)(ring_cursor + value2) + 1) < ring_entry_count) {
            x2 = (uint8_t)((a >> 8 << 8) | (uint8_t)(ring_cursor + value2));
        } else {
            uint8_t x1;
            if ((uint8_t)((uint8_t)((uint8_t)(ring_cursor + value2) + 1) - ring_entry_count) != value2) {
                x1 = (uint8_t)((a >> 8 << 8) | (uint8_t)((uint8_t)((uint8_t)(ring_cursor + value2) + 1) - ring_entry_count));
            } else {
                x1 = (uint8_t)(ring_entry_count - 1);
            }
            x2 = x1;
        }
        a1 = x2;
        a_hi1 = a >> 8;
    } else {
        r->a = (a >> 8 << 8) | value;
        r->x = (uint8_t)x;
        r->y = (uint8_t)y;
        r->mf = 1;
        r->xf = 1;
        r->sp -= 1;
        JSL(c, 0xD53D, 0xC06BE2); /* calculate_wrapped_native_menu_row_index */
        r->sp += 1;
        uint16_t a_all = r->a;
        a1 = (uint8_t)a_all;
        a_hi1 = a_all >> 8;
    }
    r->a = (a_hi1 << 8) | (uint8_t)(a1 + (uint8_t)a);
    r->y = (uint8_t)y;
    r->v = ((a1 ^ (uint8_t)(a1 + (uint8_t)a)) & ((uint8_t)a ^ (uint8_t)(a1 + (uint8_t)a)) & 0x80) != 0;
    r->mf = 1;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD0D530, SOM_RTS, "gen", add_wrapped_menu_row_to_inventory_label_offset, 0, L_A | L_B | L_Y | L_V, 1, -1, -1, 52, 27)
