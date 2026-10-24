#include "som_c.h"

/* 7E84AE test_distinct_component_offset   [class B, 61 bytes, 34 instructions]
 * Source: src/boot/test_distinct_component_offset.s
 * Documented in docs/boot.md
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: ABXYV.
 */
static void test_distinct_component_offset(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    if ((uint32_t)(uint16_t)(sp0 - 5) + 0x2 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 5), x);
    uint8_t a1 = (uint8_t)(sp0 - 5);
    uint8_t a_hi1 = (uint16_t)(sp0 - 5) >> 8;
    uint16_t y1 = y;
    for (;;) {
        uint16_t value = RAM16(0x0001 + (uint16_t)(sp0 - 5));
        uint8_t a2;
        if (y1 >= value) {
            a2 = 1;
        } else {
            uint8_t value2 = BUS8_RDP(c, (db << 0x10) + y1);
            uint8_t value3 = BUS8_RDP(c, (db << 0x10) + x);
            if (value2 != value3) {
                uint8_t a1_next = (uint8_t)(y1 + 4);
                uint8_t a_hi1_next = (uint16_t)(y1 + 4) >> 8;
                uint16_t y1_next = (uint16_t)(y1 + 4);
                a1 = a1_next;
                a_hi1 = a_hi1_next;
                y1 = y1_next;
                continue;
            }
            uint8_t value4 = BUS8_RDP(c, (db << 0x10) + 1 + y1);
            uint8_t value5 = BUS8_RDP(c, (db << 0x10) + 1 + x);
            if (value4 != value5) {
                uint8_t a1_next2 = (uint8_t)(y1 + 4);
                uint8_t a_hi1_next2 = (uint16_t)(y1 + 4) >> 8;
                uint16_t y1_next2 = (uint16_t)(y1 + 4);
                a1 = a1_next2;
                a_hi1 = a_hi1_next2;
                y1 = y1_next2;
                continue;
            }
            uint8_t value6 = BUS8_RDP(c, (db << 0x10) + 2 + y1);
            uint8_t value7 = BUS8_RDP(c, (db << 0x10) + 2 + x);
            if ((uint8_t)(value6 - value7) != 0) {
                uint8_t a1_next3 = (uint8_t)(y1 + 4);
                uint8_t a_hi1_next3 = (uint16_t)(y1 + 4) >> 8;
                uint16_t y1_next3 = (uint16_t)(y1 + 4);
                a1 = a1_next3;
                a_hi1 = a_hi1_next3;
                y1 = y1_next3;
                continue;
            }
            a2 = (uint8_t)(value6 - value7);
        }
        a1 = a2;
        break;
    }
    RAM8(0x0000 + sp0 - 3) = a1;
    r->a = (a_hi1 << 8) | RAM8(0x0000 + sp0 - 3);
    r->x = x;
    r->y = y1;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7E84AE, SOM_RTS, "gen", test_distinct_component_offset, 0, L_A | L_B | L_X | L_Y | L_V, 5, 1, 0, 61, 34)
