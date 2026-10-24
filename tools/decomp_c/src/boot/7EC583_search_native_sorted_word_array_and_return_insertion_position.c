#include "som_c.h"

/* 7EC583 search_native_sorted_word_array_and_return_insertion_position   [class B, 78 bytes, 50 instructions]
 * Source: src/boot/search_native_sorted_word_array_and_return_insertion_position.s
 * Documented in docs/boot-native-sorted-word-array.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: X.
 */
static void search_native_sorted_word_array_and_return_insertion_position(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 7) + 0x4 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a_hi;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)((a_hi << 8) | a);
    uint16_t value = RAM16(0x0000 + sp0 - 4);
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 7), x);
    uint16_t x4;
    if ((uint16_t)(value << 1) == 0) {
        x4 = x;
    } else {
        uint16_t value2 = RAM16(0x0001 + (uint16_t)(sp0 - 7));
        RAM16_SET(0x0003 + (uint16_t)(sp0 - 7), (uint16_t)((uint16_t)(value << 1) + value2));
        uint16_t value3 = RAM16(0x0001 + (uint16_t)(sp0 - 7));
        uint8_t a1 = (uint8_t)((uint16_t)((uint16_t)(value << 1) + value2) + value3);
        uint8_t a_hi1 = (uint16_t)((uint16_t)((uint16_t)(value << 1) + value2) + value3) >> 8;
        uint16_t x1 = x;
        uint16_t y1 = y;
        bool carry1 = (uint16_t)((uint16_t)(value << 1) + value2) + value3 > 0xFFFF;
        for (;;) {
            uint16_t value4 = RAM16(0x0000 + (((((a_hi1 << 8) | a1) >> 1) | (carry1 << 0x0F)) & 0xFFFE));
            uint16_t x3;
            if (y1 == value4) {
                x3 = ((((a_hi1 << 8) | a1) >> 1) | (carry1 << 0x0F)) & 0xFFFE;
            } else {
                uint16_t x2;
                if (y1 < value4) {
                    RAM16_SET(0x0003 + (uint16_t)(sp0 - 7), ((((a_hi1 << 8) | a1) >> 1) | (carry1 << 0x0F)) & 0xFFFE);
                    uint16_t value5 = RAM16(0x0001 + (uint16_t)(sp0 - 7));
                    if ((((((a_hi1 << 8) | a1) >> 1) | (carry1 << 0x0F)) & 0xFFFE) != value5) {
                        uint8_t a1_next = (uint8_t)((((((a_hi1 << 8) | a1) >> 1) | (carry1 << 0x0F)) & 0xFFFE) + value5);
                        uint8_t a_hi1_next = (uint16_t)((((((a_hi1 << 8) | a1) >> 1) | (carry1 << 0x0F)) & 0xFFFE) + value5) >> 8;
                        uint16_t x1_next = ((((a_hi1 << 8) | a1) >> 1) | (carry1 << 0x0F)) & 0xFFFE;
                        bool carry1_next = (((((a_hi1 << 8) | a1) >> 1) | (carry1 << 0x0F)) & 0xFFFE) + value5 > 0xFFFF;
                        a1 = a1_next;
                        a_hi1 = a_hi1_next;
                        x1 = x1_next;
                        carry1 = carry1_next;
                        continue;
                    }
                    x2 = ((((a_hi1 << 8) | a1) >> 1) | (carry1 << 0x0F)) & 0xFFFE;
                } else {
                    RAM16_SET(0x0001 + (uint16_t)(sp0 - 7), (uint16_t)((((((a_hi1 << 8) | a1) >> 1) | (carry1 << 0x0F)) & 0xFFFE) + 2));
                    uint16_t value6 = RAM16(0x0003 + (uint16_t)(sp0 - 7));
                    if ((uint16_t)((((((a_hi1 << 8) | a1) >> 1) | (carry1 << 0x0F)) & 0xFFFE) + 2) != value6) {
                        uint8_t a1_next2 = (uint8_t)((uint16_t)((((((a_hi1 << 8) | a1) >> 1) | (carry1 << 0x0F)) & 0xFFFE) + 2) + value6);
                        uint8_t a_hi1_next2 = (uint16_t)((uint16_t)((((((a_hi1 << 8) | a1) >> 1) | (carry1 << 0x0F)) & 0xFFFE) + 2) + value6) >> 8;
                        uint16_t x1_next2 = (uint16_t)((((((a_hi1 << 8) | a1) >> 1) | (carry1 << 0x0F)) & 0xFFFE) + 2);
                        bool carry1_next2 = (uint16_t)((((((a_hi1 << 8) | a1) >> 1) | (carry1 << 0x0F)) & 0xFFFE) + 2) + value6 > 0xFFFF;
                        a1 = a1_next2;
                        a_hi1 = a_hi1_next2;
                        x1 = x1_next2;
                        carry1 = carry1_next2;
                        continue;
                    }
                    x2 = (uint16_t)((((((a_hi1 << 8) | a1) >> 1) | (carry1 << 0x0F)) & 0xFFFE) + 2);
                }
                x3 = x2;
            }
            x1 = x3;
            break;
        }
        x4 = x1;
    }
    uint8_t value11 = RAM8(0x0000 + sp0 - 2);
    uint8_t value12 = RAM8(0x0000 + sp0 - 1);
    uint8_t value13 = RAM8(0x0000 + sp0);
    r->x = x4;
    r->mf = value11 & 0x20;
    r->xf = value11 & 0x10;
    r->dp = (value13 << 8) | value12;
    r->i = value11 & 0x04;
    r->d = value11 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EC583, SOM_RTS, "gen", search_native_sorted_word_array_and_return_insertion_position, 0, L_X, 7, 1, 0, 78, 50)
