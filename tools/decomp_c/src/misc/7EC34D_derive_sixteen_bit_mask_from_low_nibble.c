#include "som_c.h"

/* 7EC34D derive_sixteen_bit_mask_from_low_nibble   [class B, 24 bytes, 15 instructions]
 * Source: src/boot/derive_sixteen_bit_mask_from_low_nibble.s
 * Documented in docs/boot-native-low-nibble-mask.md
 * Entry: M=any X=16 bit DB=$7F D=any.  Callers read: BXYV.
 */
static void derive_sixteen_bit_mask_from_low_nibble(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7F, -1, 0)) return;
    const uint16_t a = r->a;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint8_t a2;
    uint8_t a_hi2;
    if ((a & 0x0F) == 0) {
        a2 = 1;
        a_hi2 = 0;
    } else {
        uint8_t a1 = 1;
        uint8_t a_hi1 = 0;
        uint16_t x1 = a & 0x0F;
        for (;;) {
            uint8_t a1_next = (uint8_t)(((a_hi1 << 8) | a1) << 1);
            uint8_t a_hi1_next = (uint16_t)(((a_hi1 << 8) | a1) << 1) >> 8;
            uint16_t x1_next = (uint16_t)(x1 - 1);
            a1 = a1_next;
            a_hi1 = a_hi1_next;
            x1 = x1_next;
            if (!(x1 != 0)) break;
        }
        a2 = a1;
        a_hi2 = a_hi1;
    }
    r->a = (a_hi2 << 8) | a2;
    r->x = (a_hi2 << 8) | a2;
    r->y = y;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EC34D, SOM_RTS, "gen", derive_sixteen_bit_mask_from_low_nibble, 0, L_B | L_X | L_Y | L_V, 3, -1, 0, 24, 15)
