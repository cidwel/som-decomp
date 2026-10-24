#include "som_c.h"

/* C02366 assemble_thirty_two_native_menu_text_rows   [class A, 33 bytes, 15 instructions]
 * Source: src/rom/assemble_thirty_two_native_menu_text_rows.s
 * Documented in docs/event-menu-graphics.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZV.
 */
static void assemble_thirty_two_native_menu_text_rows(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const bool carry = r->c;
    const bool overflow = r->v;
    RAM8(0xA176) = 0x20;
    uint8_t a1 = 0x20;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = 0;
    uint16_t y1 = 0;
    bool carry1 = carry;
    bool zero1 = 0;
    bool overflow1 = overflow;
    do {
        r->a = (a_hi1 << 8) | a1;
        r->x = x1;
        r->y = y1;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0;
        JSR(c, 0x2373, 0xC02387); /* assemble_native_menu_doubled_text_half_row */
        r->mf = 1;
        r->xf = 0;
        JSR(c, 0x2376, 0xC02387); /* assemble_native_menu_doubled_text_half_row */
        uint16_t x_ret2 = r->x;
        uint16_t y_ret2 = r->y;
        RAM8(0xA176)--;
        a1 = (uint8_t)(x_ret2 + 0x20);
        a_hi1 = (uint16_t)(x_ret2 + 0x20) >> 8;
        x1 = (uint16_t)(x_ret2 + 0x20);
        y1 = y_ret2;
        carry1 = x_ret2 + 0x20 > 0xFFFF;
        zero1 = RAM8(0xA176) == 0;
        overflow1 = ((x_ret2 ^ (uint16_t)(x_ret2 + 0x20)) & ((uint16_t)(x_ret2 + 0x20) ^ 0x20) & 0x8000) != 0;
    } while (RAM8(0xA176) != 0);
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->z = zero1;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC02366, SOM_RTS, "gen", assemble_thirty_two_native_menu_text_rows, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_V, 1, 1, 0, 33, 15)
