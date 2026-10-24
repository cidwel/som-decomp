#include "som_c.h"

/* C10AA3 find_first_eligible_hero_on_screen   [class B, 57 bytes, 32 instructions]
 * Source: src/rom/find_first_eligible_hero_on_screen.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: AYV.
 */
static void find_first_eligible_hero_on_screen(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7E;
    RAM8(0x0001 + (uint16_t)(sp0 - 4)) = 3;
    uint8_t a1 = 3;
    uint8_t a_hi1 = (uint16_t)(sp0 - 4) >> 8;
    uint16_t x1 = 0xE000;
    uint16_t y1 = y;
    bool carry1 = carry;
    bool zero1 = 0;
    bool negative1 = 1;
    bool overflow1 = overflow;
    for (;;) {
        r->a = (a_hi1 << 8) | a1;
        r->x = x1;
        r->y = y1;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = (uint16_t)(sp0 - 4);
        r->sp -= 4;
        JSR(c, 0x0AB5, 0xC1054A); /* test_actor_target_eligibility */
        r->sp += 4;
        uint16_t x_ret = r->x;
        bool zero_ret = r->z;
        uint8_t a4;
        uint8_t a_hi4;
        if (!zero_ret) {
            RAM8(0x0001 + (uint16_t)(sp0 - 4))--;
            if (RAM8(0x0001 + (uint16_t)(sp0 - 4)) != 0) {
                a1 = (uint8_t)(x_ret + 0x0200);
                a_hi1 = (uint16_t)(x_ret + 0x0200) >> 8;
                x1 = (uint16_t)(x_ret + 0x0200);
                carry1 = x_ret + 0x0200 > 0xFFFF;
                zero1 = RAM8(0x0001 + (uint16_t)(sp0 - 4)) == 0;
                negative1 = RAM8(0x0001 + (uint16_t)(sp0 - 4)) & 0x80;
                overflow1 = ((x_ret ^ (uint16_t)(x_ret + 0x0200)) & ((uint16_t)(x_ret + 0x0200) ^ 0x0200) & 0x8000) != 0;
                continue;
            }
            a4 = 0xFF;
            a_hi4 = (uint16_t)(x_ret + 0x0200) >> 8;
        } else {
            r->mf = 1;
            r->xf = 0;
            r->sp -= 4;
            JSR(c, 0x0ABA, 0xC10358); /* classify_actor_squared_distance */
            r->sp += 4;
            uint16_t a_all2 = r->a;
            uint8_t a3;
            uint8_t a_hi3;
            if ((uint8_t)a_all2 == 0x30) {
                r->mf = 1;
                r->xf = 0;
                r->sp -= 4;
                JSR(c, 0x0AD5, 0xC105CF); /* actor_slot_from_address_high_byte */
                r->sp += 4;
                uint16_t a_all3 = r->a;
                a3 = (uint8_t)a_all3;
                a_hi3 = a_all3 >> 8;
            } else {
                uint8_t a2;
                uint8_t a_hi2;
                if ((uint8_t)a_all2 < 0x30) {
                    r->mf = 1;
                    r->xf = 0;
                    r->sp -= 4;
                    JSR(c, 0x0AD5, 0xC105CF); /* actor_slot_from_address_high_byte */
                    r->sp += 4;
                    uint16_t a_all4 = r->a;
                    a2 = (uint8_t)a_all4;
                    a_hi2 = a_all4 >> 8;
                } else {
                    RAM8(0x0001 + (uint16_t)(sp0 - 4))--;
                    if (RAM8(0x0001 + (uint16_t)(sp0 - 4)) != 0) {
                        a1 = (uint8_t)(x_ret + 0x0200);
                        a_hi1 = (uint16_t)(x_ret + 0x0200) >> 8;
                        x1 = (uint16_t)(x_ret + 0x0200);
                        carry1 = x_ret + 0x0200 > 0xFFFF;
                        zero1 = RAM8(0x0001 + (uint16_t)(sp0 - 4)) == 0;
                        negative1 = RAM8(0x0001 + (uint16_t)(sp0 - 4)) & 0x80;
                        overflow1 = ((x_ret ^ (uint16_t)(x_ret + 0x0200)) & ((uint16_t)(x_ret + 0x0200) ^ 0x0200) & 0x8000) != 0;
                        continue;
                    }
                    a2 = 0xFF;
                    a_hi2 = (uint16_t)(x_ret + 0x0200) >> 8;
                }
                a3 = a2;
                a_hi3 = a_hi2;
            }
            a4 = a3;
            a_hi4 = a_hi3;
        }
        RAM8(0x0000 + sp0 - 3) = a4;
        uint8_t value = RAM8(0x0000 + sp0 - 3);
        uint8_t value2 = RAM8(0x0000 + sp0 - 1);
        uint8_t value3 = RAM8(0x0000 + sp0);
        r->a = (a_hi4 << 8) | value;
        r->v = overflow;
        r->mf = 1;
        r->xf = 0;
        r->dp = (value3 << 8) | value2;
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC10AA3, SOM_RTS, "gen", find_first_eligible_hero_on_screen, 0, L_A | L_Y | L_V, 4, 1, 0, 57, 32)
