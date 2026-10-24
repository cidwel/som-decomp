#include "som_c.h"

/* C07908 clear_native_menu_ring_blink_bit_in_twelve_rows   [class A, 26 bytes, 12 instructions]
 * Source: src/rom/clear_native_menu_ring_blink_bit_in_twelve_rows.s
 * Entry: M=any X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void clear_native_menu_ring_blink_bit_in_twelve_rows(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, -1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t a1 = (uint8_t)a;
    uint8_t a_hi1 = a >> 8;
    uint16_t x1 = 0;
    bool carry1 = carry;
    bool zero1 = 1;
    bool negative1 = 0;
    bool overflow1 = overflow;
    for (;;) {
        uint16_t value = BUS16(c, 0x0018C0 + x1);
        BUS16_SET(c, 0x0018C0 + x1, value & 0xFF7F);
        uint8_t a1_next = (uint8_t)(x1 + 0x10);
        uint8_t a_hi1_next = (uint16_t)(x1 + 0x10) >> 8;
        uint16_t x1_next = (uint16_t)(x1 + 0x10);
        bool carry1_next = (uint16_t)(x1 + 0x10) >= 0xC0;
        bool zero1_next = (uint16_t)(x1 + 0x10) == 0xC0;
        bool negative1_next = (uint16_t)((uint16_t)(x1 + 0x10) - 0xC0) & 0x8000;
        bool overflow1_next = ((x1 ^ (uint16_t)(x1 + 0x10)) & ((uint16_t)(x1 + 0x10) ^ 0x10) & 0x8000) != 0;
        a1 = a1_next;
        a_hi1 = a_hi1_next;
        x1 = x1_next;
        carry1 = carry1_next;
        zero1 = zero1_next;
        negative1 = negative1_next;
        overflow1 = overflow1_next;
        if (!(x1 < 0xC0)) break;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y;
    r->c = carry1;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow1;
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC07908, SOM_RTS, "gen", clear_native_menu_ring_blink_bit_in_twelve_rows, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, -1, 0, 26, 12)
