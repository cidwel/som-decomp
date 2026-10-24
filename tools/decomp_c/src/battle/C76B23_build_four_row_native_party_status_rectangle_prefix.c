#include "som_c.h"

/* C76B23 build_four_row_native_party_status_rectangle_prefix   [class C, 50 bytes, 27 instructions]
 * Source: src/rom/build_four_row_native_party_status_rectangle_prefix.s
 * Documented in docs/ui-native-party-status-art.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZV.
 */
static void build_four_row_native_party_status_rectangle_prefix(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    RAM16_SET(0xA173, y);
    RAM16_SET(0xA171, 4);
    uint8_t a1 = (uint8_t)a;
    uint8_t a_hi1 = a >> 8;
    uint16_t x1 = x;
    uint16_t y1 = 4;
    bool carry1 = carry;
    bool zero1 = 0;
    bool overflow1 = overflow;
    do {
        uint16_t value = RAM16(0xA173);
        uint8_t a2 = a1;
        uint8_t a_hi2 = a_hi1;
        uint16_t x2 = x1;
        uint16_t y2 = value;
        for (;;) {
            RAM16_SET(0x9000 + x2, (a_hi2 << 8) | a2);
            RAM16_SET(0x9040 + x2, (uint16_t)(((a_hi2 << 8) | a2) + 2));
            uint8_t a2_next = (uint8_t)(((a_hi2 << 8) | a2) + 4);
            uint8_t a_hi2_next = (uint16_t)(((a_hi2 << 8) | a2) + 4) >> 8;
            uint16_t x2_next = (uint16_t)(x2 + 2);
            uint16_t y2_next = (uint16_t)(y2 - 1);
            a2 = a2_next;
            a_hi2 = a_hi2_next;
            x2 = x2_next;
            y2 = y2_next;
            if (!(y2 != 0)) break;
        }
        RAM16_SET(0xA171, (uint16_t)(RAM16(0xA171) - 1));
        uint8_t a1_next = (uint8_t)((a_hi2 << 8) | a2);
        uint8_t a_hi1_next = a_hi2;
        uint16_t x1_next = (uint16_t)(x1 + 0x80);
        uint16_t y1_next = (a_hi2 << 8) | a2;
        bool carry1_next = x1 + 0x80 > 0xFFFF;
        bool zero1_next = RAM16(0xA171) == 0;
        bool overflow1_next = ((x1 ^ (uint16_t)(x1 + 0x80)) & ((uint16_t)(x1 + 0x80) ^ 0x80) & 0x8000) != 0;
        a1 = a1_next;
        a_hi1 = a_hi1_next;
        x1 = x1_next;
        y1 = y1_next;
        carry1 = carry1_next;
        zero1 = zero1_next;
        overflow1 = overflow1_next;
    } while (RAM16(0xA171) != 0);
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->z = zero1;
    r->v = overflow1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC76B23, SOM_RTS, "gen", build_four_row_native_party_status_rectangle_prefix, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_V, 2, 0, 0, 50, 27)
