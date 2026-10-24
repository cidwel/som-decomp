#include "som_c.h"

/* C127B4 highest_set_bit_word_index_copy_three   [class B, 24 bytes, 16 instructions]
 * Source: src/rom/highest_set_bit_word_index_copy_three.s
 * Documented in docs/source-recovery-parallel-bit-index-copies.md
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void highest_set_bit_word_index_copy_three(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t dp = r->dp;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t a1 = (uint8_t)x;
    uint8_t a_hi1 = x >> 8;
    uint16_t x1 = 0x10;
    for (;;) {
        uint8_t a2;
        uint8_t a_hi2;
        uint16_t x2;
        if (((a_hi1 << 8) | a1) & 0x8000) {
            a2 = (uint8_t)(x1 - 1);
            a_hi2 = (uint16_t)(x1 - 1) >> 8;
            x2 = x1;
        } else {
            if ((uint16_t)(x1 - 1) != 0) {
                uint8_t a1_next = (uint8_t)(((a_hi1 << 8) | a1) << 1);
                uint8_t a_hi1_next = (uint16_t)(((a_hi1 << 8) | a1) << 1) >> 8;
                uint16_t x1_next = (uint16_t)(x1 - 1);
                a1 = a1_next;
                a_hi1 = a_hi1_next;
                x1 = x1_next;
                continue;
            }
            a2 = 0xFF;
            a_hi2 = 0;
            x2 = (uint16_t)(x1 - 1);
        }
        a1 = a2;
        a_hi1 = a_hi2;
        x1 = x2;
        break;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y;
    r->c = carry;
    r->z = dp == 0;
    r->n = dp & 0x8000;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC127B4, SOM_RTS, "gen", highest_set_bit_word_index_copy_three, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 3, 1, 0, 24, 16)
