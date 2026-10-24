#include "som_c.h"

/* 7EC37D fill_native_boot_memory_using_words_or_forward_copy   [class B, 66 bytes, 41 instructions]
 * Source: src/boot/fill_native_boot_memory_using_words_or_forward_copy.s
 * Documented in docs/boot-native-resource-memory.md
 * Entry: M=8 bit X=16 bit DB=$7F D=any.  Callers read: YCV.
 */
static void fill_native_boot_memory_using_words_or_forward_copy(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    const uint16_t dp = r->dp;
    const uint8_t a = r->a & 0xFF;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint16_t y7;
    if (y == 0) {
        y7 = y;
    } else {
        RAM8(0x10000 + x) = a;
        uint16_t y6;
        if (y < 0x81) {
            uint16_t y4;
            if (((uint8_t)y & 1) == 0) {
                uint16_t x1 = x;
                uint16_t y1 = y;
                for (;;) {
                    RAM16_SET(0x10000 + x1, (a << 8) | a);
                    x1 = (uint16_t)(x1 + 2);
                    y1 = (uint16_t)(y1 - 2);
                    if (!(y1 != 0)) break;
                }
                y4 = y1;
            } else {
                uint16_t y3;
                if ((uint16_t)(y - 1) == 0) {
                    y3 = (uint16_t)(y - 1);
                } else {
                    uint16_t x2 = (uint16_t)(x + 1);
                    uint16_t y2 = (uint16_t)(y - 1);
                    for (;;) {
                        RAM16_SET(0x10000 + x2, (a << 8) | a);
                        x2 = (uint16_t)(x2 + 2);
                        y2 = (uint16_t)(y2 - 2);
                        if (!(y2 != 0)) break;
                    }
                    y3 = y2;
                }
                y4 = y3;
            }
            y6 = y4;
        } else {
            uint16_t y5;
            if ((uint16_t)(y - 1) == 0) {
                y5 = (uint16_t)(x + 1);
            } else {
                r->a = (uint16_t)(y - 1);
                r->y = (uint16_t)(x + 1);
                r->c = y >= 0x81;
                r->z = (uint16_t)(y - 1) == 0;
                r->n = (uint16_t)(y - 1) & 0x8000;
                r->sp -= 3;
                JSR(c, 0xC39C, 0x7EC3BF); /* copy_native_same_bank_memory_through_stack_generated_mvn */
                r->sp += 3;
                uint16_t y_ret = r->y;
                y5 = y_ret;
            }
            y6 = y5;
        }
        y7 = y6;
    }
    r->y = y7;
    r->c = carry;
    r->v = overflow;
    r->mf = 1;
    r->xf = 0;
    r->dp = dp;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EC37D, SOM_RTS, "gen", fill_native_boot_memory_using_words_or_forward_copy, 0, L_Y | L_C | L_V, 4, 1, 0, 66, 41)
