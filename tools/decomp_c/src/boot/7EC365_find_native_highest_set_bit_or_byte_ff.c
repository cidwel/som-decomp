#include "som_c.h"

/* 7EC365 find_native_highest_set_bit_or_byte_ff   [class B, 24 bytes, 16 instructions]
 * Source: src/boot/find_native_highest_set_bit_or_byte_ff.s
 * Documented in docs/boot-native-title-random.md
 * Entry: M=any X=16 bit DB=$7F D=any.  Callers read: ABXY.
 */
static void find_native_highest_set_bit_or_byte_ff(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7F, -1, 0)) return;
    const uint8_t m_entry = r->mf;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
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
    r->mf = m_entry;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EC365, SOM_RTS, "gen", find_native_highest_set_bit_or_byte_ff, 0, L_A | L_B | L_X | L_Y, 3, -1, 0, 24, 16)
