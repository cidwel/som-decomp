#include "som_c.h"

/* C07F43 set_latent_shop_active_ring_bit_prefix   [class C, 80 bytes, 35 instructions]
 * Source: src/rom/set_latent_shop_active_ring_bit_prefix.s
 * Entry: M=any X=any DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void set_latent_shop_active_ring_bit_prefix(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, -1)) return;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    RAM8(0x1803) |= 0x40;
    r->a = (a >> 8 << 8) | 0x40;
    r->mf = 1;
    JSR(c, 0x7F4C, 0xC07A89); /* external */
    r->mf = 1; /* sep */
    uint16_t a_all = r->a;
    RAM8(0x1804) |= 0x80;
    r->a = (a_all >> 8 << 8) | 0x80;
    r->x = 0xFF3C;
    r->z = 0;
    r->n = 1;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x7F5B, 0xC07C94); /* external */
    r->mf = 1; /* sep */
    uint16_t a_all2 = r->a;
    uint16_t x_ret2 = r->x;
    uint16_t y_ret = r->y;
    bool overflow_ret2 = r->v;
    RAM8(0x1804) &= 0x7F;
    uint8_t a_hi1 = a_all2 >> 8;
    uint16_t x1 = x_ret2;
    uint16_t y1 = y_ret;
    bool overflow1 = overflow_ret2;
    bool first_pass = true;
    for (;;) {
        if (first_pass) {
            uint8_t value4 = RAM8(0x1801);
            uint8_t a1;
            uint8_t a_hi2;
            uint16_t x2;
            uint16_t y2;
            bool carry1;
            bool zero1;
            bool negative1;
            bool overflow2;
            if (value4 == 0x80) {
                a1 = value4;
                a_hi2 = a_hi1;
                x2 = x1;
                y2 = y1;
                carry1 = value4 >= 0x80;
                zero1 = value4 == 0x80;
                negative1 = (uint8_t)(value4 - 0x80) & 0x80;
                overflow2 = overflow1;
            } else {
                if (value4 != 0x40) {
                    r->a = (a_hi1 << 8) | value4;
                    r->x = x1;
                    r->y = y1;
                    r->c = value4 >= 0x40;
                    r->z = value4 == 0x40;
                    r->n = (uint8_t)(value4 - 0x40) & 0x80;
                    r->v = overflow1;
                    r->mf = 1;
                    r->xf = 0;
                    r->db = 0x7E;
                    r->dp = dp;
                    JSR(c, 0x7F72, 0xC07F93); /* tick_latent_shop_input_or_enter_literal_brk */
                    uint16_t a_all4 = r->a;
                    uint16_t x_ret4 = r->x;
                    uint16_t y_ret3 = r->y;
                    bool overflow_ret4 = r->v;
                    a_hi1 = a_all4 >> 8;
                    x1 = x_ret4;
                    y1 = y_ret3;
                    overflow1 = overflow_ret4;
                    first_pass = false;
                    continue;
                }
                RAM8(0x1803) |= 2;
                r->a = (a_hi1 << 8) | 2;
                r->x = x1;
                r->y = y1;
                r->c = value4 >= 0x40;
                r->v = overflow1;
                r->mf = 1;
                r->xf = 0;
                r->db = 0x7E;
                r->dp = dp;
                JSR(c, 0x7F7E, 0xC07FE8); /* request_latent_shop_description_refresh_and_wait_for_dialogue */
                r->mf = 1; /* sep */
                uint16_t a_all3 = r->a;
                uint16_t x_ret3 = r->x;
                uint16_t y_ret2 = r->y;
                bool carry_ret3 = r->c;
                bool overflow_ret3 = r->v;
                a1 = 1;
                a_hi2 = a_all3 >> 8;
                x2 = x_ret3;
                y2 = y_ret2;
                carry1 = carry_ret3;
                zero1 = 0;
                negative1 = 0;
                overflow2 = overflow_ret3;
            }
            r->a = (a_hi2 << 8) | a1;
            r->x = x2;
            r->y = y2;
            r->c = carry1;
            r->z = zero1;
            r->n = negative1;
            r->v = overflow2;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = dp;
            r->sp -= 1;
            JSR(c, 0x7F86, 0xC07A47); /* external */
            r->sp += 1;
            r->mf = 1;
            r->xf = 0;
            r->sp -= 1;
            JSR(c, 0x7F89, 0xC07F93); /* tick_latent_shop_input_or_enter_literal_brk */
            r->sp += 1;
            r->mf = 1; /* sep */
            RAM8(0x1803) &= 0xBF;
            SET_A8(r, 0x40);
            r->c = carry1;
            r->z = zero1;
            r->n = negative1;
            r->v = overflow2;
            r->mf = 1;
            r->xf = 0;
            RETURN_RTS(c);
        } else {
            uint8_t value7 = RAM8(0x1801);
            uint8_t a2;
            uint8_t a_hi3;
            uint16_t x3;
            uint16_t y3;
            bool carry2;
            bool zero2;
            bool negative2;
            bool overflow3;
            if (value7 == 0x80) {
                a2 = value7;
                a_hi3 = a_hi1;
                x3 = x1;
                y3 = y1;
                carry2 = value7 >= 0x80;
                zero2 = value7 == 0x80;
                negative2 = (uint8_t)(value7 - 0x80) & 0x80;
                overflow3 = overflow1;
            } else {
                if (value7 != 0x40) {
                    r->a = (a_hi1 << 8) | value7;
                    r->x = x1;
                    r->y = y1;
                    r->c = value7 >= 0x40;
                    r->z = value7 == 0x40;
                    r->n = (uint8_t)(value7 - 0x40) & 0x80;
                    r->v = overflow1;
                    r->mf = 1;
                    r->xf = 0;
                    r->db = 0x7E;
                    r->dp = dp;
                    JSR(c, 0x7F72, 0xC07F93); /* tick_latent_shop_input_or_enter_literal_brk */
                    uint16_t a_all8 = r->a;
                    uint16_t x_ret8 = r->x;
                    uint16_t y_ret7 = r->y;
                    bool overflow_ret8 = r->v;
                    a_hi1 = a_all8 >> 8;
                    x1 = x_ret8;
                    y1 = y_ret7;
                    overflow1 = overflow_ret8;
                    continue;
                }
                RAM8(0x1803) |= 2;
                r->a = (a_hi1 << 8) | 2;
                r->x = x1;
                r->y = y1;
                r->c = value7 >= 0x40;
                r->v = overflow1;
                r->mf = 1;
                r->xf = 0;
                r->db = 0x7E;
                r->dp = dp;
                JSR(c, 0x7F7E, 0xC07FE8); /* request_latent_shop_description_refresh_and_wait_for_dialogue */
                r->mf = 1; /* sep */
                uint16_t a_all7 = r->a;
                uint16_t x_ret7 = r->x;
                uint16_t y_ret6 = r->y;
                bool carry_ret7 = r->c;
                bool overflow_ret7 = r->v;
                a2 = 1;
                a_hi3 = a_all7 >> 8;
                x3 = x_ret7;
                y3 = y_ret6;
                carry2 = carry_ret7;
                zero2 = 0;
                negative2 = 0;
                overflow3 = overflow_ret7;
            }
            r->a = (a_hi3 << 8) | a2;
            r->x = x3;
            r->y = y3;
            r->c = carry2;
            r->z = zero2;
            r->n = negative2;
            r->v = overflow3;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = dp;
            r->sp -= 1;
            JSR(c, 0x7F86, 0xC07A47); /* external */
            r->sp += 1;
            r->mf = 1;
            r->xf = 0;
            r->sp -= 1;
            JSR(c, 0x7F89, 0xC07F93); /* tick_latent_shop_input_or_enter_literal_brk */
            r->sp += 1;
            r->mf = 1; /* sep */
            RAM8(0x1803) &= 0xBF;
            SET_A8(r, 0x40);
            r->c = carry2;
            r->z = zero2;
            r->n = negative2;
            r->v = overflow3;
            r->mf = 1;
            r->xf = 0;
            RETURN_RTS(c);
        }
    }
}
SOM_REGISTER(0xC07F43, SOM_RTS, "hand", set_latent_shop_active_ring_bit_prefix, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, -1, -1, 80, 35)
