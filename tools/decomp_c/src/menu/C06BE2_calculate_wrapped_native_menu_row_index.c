#include "som_c.h"

/* C06BE2 calculate_wrapped_native_menu_row_index   [class A, 22 bytes, 10 instructions]
 * Source: src/rom/calculate_wrapped_native_menu_row_index.s
 * Documented in docs/event-menu-text-tick.md
 * Entry: M=any X=16 bit DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void calculate_wrapped_native_menu_row_index(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, -1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint8_t ring_cursor = RAM8(RING_CURSOR);
    uint8_t value = RAM8(0x182E);
    uint8_t ring_entry_count = RAM8(RING_ENTRY_COUNT);
    uint8_t a1;
    bool overflow1;
    if ((uint8_t)(ring_cursor + value) < ring_entry_count) {
        a1 = (uint8_t)(ring_cursor + value);
        overflow1 = ((ring_cursor ^ (uint8_t)(ring_cursor + value)) & (value ^ (uint8_t)(ring_cursor + value)) & 0x80) != 0;
    } else {
        a1 = (uint8_t)((uint8_t)(ring_cursor + value) - ring_entry_count);
        overflow1 = (((uint8_t)(ring_cursor + value) ^ ring_entry_count) & ((uint8_t)(ring_cursor + value) ^ (uint8_t)((uint8_t)(ring_cursor + value) - ring_entry_count)) & 0x80) != 0;
    }
    RAM8(0x1835) = a1;
    SET_A8(r, a1);
    r->c = (uint8_t)(ring_cursor + value) >= ring_entry_count;
    r->v = overflow1;
    r->mf = 1;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC06BE2, SOM_RTL, "gen", calculate_wrapped_native_menu_row_index, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, -1, 0, 22, 10)
