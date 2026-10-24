#include "som_c.h"

/* C026B3 consume_native_menu_four_by_four_pattern   [class B, 73 bytes, 44 instructions]
 * Source: src/rom/consume_native_menu_four_by_four_pattern.s
 * Documented in docs/event-menu-page-records.md
 * Entry: M=8 bit X=16 bit DB=$C7 D=$0000.  Callers read: ABXYCZNV.
 */
static void consume_native_menu_four_by_four_pattern(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0xC7, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint16_t value = BUS16(c, 0xC70000 + y);
    RAM8(0xA178) = 4;
    uint8_t a1 = 4;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = value;
    uint16_t y1 = 0x38;
    bool carry1 = carry;
    bool overflow1 = overflow;
    do {
        RAM8(0xA171) = 4;
        uint8_t a_hi2 = a_hi1;
        uint16_t x2 = x1;
        uint16_t y2 = y1;
        do {
            r->a = (a_hi2 << 8) | (uint8_t)y2;
            r->x = x2;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0;
            r->sp -= 9;
            JSR(c, 0x26D1, 0xC026FC); /* expand_native_menu_four_by_four_tile_pattern */
            r->sp += 9;
            RAM8(0xA171)--;
            uint8_t a_hi2_next = (uint16_t)(x2 + 8) >> 8;
            uint16_t x2_next = (uint16_t)(x2 + 8);
            uint16_t y2_next = ((uint16_t)(x2 + 8) >> 8 << 8) | ((uint8_t)y2 ^ 4);
            a_hi2 = a_hi2_next;
            x2 = x2_next;
            y2 = y2_next;
        } while (RAM8(0xA171) != 0);
        RAM8(0xA178)--;
        uint8_t a1_next = (uint8_t)y2 ^ 4;
        uint8_t a_hi1_next = (uint16_t)(x1 + 0x0100) >> 8;
        uint16_t x1_next = (uint16_t)(x1 + 0x0100);
        uint16_t y1_next = ((uint16_t)(x1 + 0x0100) >> 8 << 8) | ((uint8_t)y2 ^ 4);
        bool carry1_next = x1 + 0x0100 > 0xFFFF;
        bool overflow1_next = ((x1 ^ (uint16_t)(x1 + 0x0100)) & ((uint16_t)(x1 + 0x0100) ^ 0x0100) & 0x8000) != 0;
        a1 = a1_next;
        a_hi1 = a_hi1_next;
        x1 = x1_next;
        y1 = y1_next;
        carry1 = carry1_next;
        overflow1 = overflow1_next;
    } while (RAM8(0xA178) != 0);
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = (uint16_t)(y + 2);
    r->c = carry1;
    r->z = 0;
    r->n = 1;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    r->db = 0xC7;
    r->dp = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC026B3, SOM_RTS, "gen", consume_native_menu_four_by_four_pattern, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 9, 1, 0, 73, 44)
