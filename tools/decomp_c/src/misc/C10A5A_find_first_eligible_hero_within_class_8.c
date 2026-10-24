#include "som_c.h"

/* C10A5A find_first_eligible_hero_within_class_8   [class B, 57 bytes, 32 instructions]
 * Source: src/rom/find_first_eligible_hero_within_class_8.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: AYV.
 */
static void find_first_eligible_hero_within_class_8(SomCtx *c)
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
    if ((uint32_t)(uint16_t)(sp0 - 4) + 0x1 > 0x1FFF) { c->fail = 3; return; }
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
    uint16_t direct_page = (uint16_t)(sp0 - 4);
    for (;;) {
        r->a = (a_hi1 << 8) | a1;
        r->x = x1;
        r->y = y1;
        r->c = carry1;
        r->z = zero1;
        r->n = negative1;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = direct_page;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0x0A6C, 0xC1054A); GUARD_JSR(c, sp_call, 0x0A6C); } /* test_actor_target_eligibility */
        r->sp += 4;
        uint16_t dp_ret = r->dp;
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t x_ret = r->x;
        bool zero_ret = r->z;
        if (!zero_ret) {
            uint8_t value = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
            BUS8_SET(c, (uint16_t)(dp_ret + 1), (uint8_t)(value - 1));
            if ((uint8_t)(value - 1) != 0) {
                a1 = (uint8_t)(x_ret + 0x0200);
                a_hi1 = (uint16_t)(x_ret + 0x0200) >> 8;
                x1 = (uint16_t)(x_ret + 0x0200);
                carry1 = x_ret + 0x0200 > 0xFFFF;
                zero1 = (uint8_t)(value - 1) == 0;
                negative1 = (uint8_t)(value - 1) & 0x80;
                overflow1 = ((x_ret ^ (uint16_t)(x_ret + 0x0200)) & ((uint16_t)(x_ret + 0x0200) ^ 0x0200) & 0x8000) != 0;
                direct_page = dp_ret;
                continue;
            }
            a1 = 0xFF;
            a_hi1 = (uint16_t)(x_ret + 0x0200) >> 8;
            x1 = (uint16_t)(x_ret + 0x0200);
            carry1 = x_ret + 0x0200 > 0xFFFF;
            zero1 = 0;
            negative1 = 1;
            overflow1 = ((x_ret ^ (uint16_t)(x_ret + 0x0200)) & ((uint16_t)(x_ret + 0x0200) ^ 0x0200) & 0x8000) != 0;
            direct_page = dp_ret;
            break;
        }
        r->mf = 1;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0x0A71, 0xC10358); GUARD_JSR(c, sp_call, 0x0A71); } /* classify_actor_squared_distance */
        r->sp += 4;
        if (r->mf != 1) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all2 = r->a;
        if ((uint8_t)a_all2 == 8) {
            r->c = (uint8_t)a_all2 >= 8;
            r->z = (uint8_t)a_all2 == 8;
            r->n = (uint8_t)((uint8_t)a_all2 - 8) & 0x80;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR(c, 0x0A8C, 0xC105CF); GUARD_JSR(c, sp_call, 0x0A8C); } /* actor_slot_from_address_high_byte */
            r->sp += 4;
            uint16_t a_all3 = r->a;
            bool carry_ret3 = r->c;
            bool zero_ret3 = r->z;
            bool negative_ret3 = r->n;
            bool overflow_ret3 = r->v;
            a1 = (uint8_t)a_all3;
            a_hi1 = a_all3 >> 8;
            x1 = x_ret;
            carry1 = carry_ret3;
            zero1 = zero_ret3;
            negative1 = negative_ret3;
            overflow1 = overflow_ret3;
            direct_page = dp_ret;
            break;
        }
        if ((uint8_t)a_all2 < 8) {
            r->c = (uint8_t)a_all2 >= 8;
            r->z = (uint8_t)a_all2 == 8;
            r->n = (uint8_t)((uint8_t)a_all2 - 8) & 0x80;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR(c, 0x0A8C, 0xC105CF); GUARD_JSR(c, sp_call, 0x0A8C); } /* actor_slot_from_address_high_byte */
            r->sp += 4;
            uint16_t a_all4 = r->a;
            bool carry_ret4 = r->c;
            bool zero_ret4 = r->z;
            bool negative_ret4 = r->n;
            bool overflow_ret4 = r->v;
            a1 = (uint8_t)a_all4;
            a_hi1 = a_all4 >> 8;
            x1 = x_ret;
            carry1 = carry_ret4;
            zero1 = zero_ret4;
            negative1 = negative_ret4;
            overflow1 = overflow_ret4;
            direct_page = dp_ret;
            break;
        }
        uint8_t value2 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
        BUS8_SET(c, (uint16_t)(dp_ret + 1), (uint8_t)(value2 - 1));
        if ((uint8_t)(value2 - 1) != 0) {
            a1 = (uint8_t)(x_ret + 0x0200);
            a_hi1 = (uint16_t)(x_ret + 0x0200) >> 8;
            x1 = (uint16_t)(x_ret + 0x0200);
            carry1 = x_ret + 0x0200 > 0xFFFF;
            zero1 = (uint8_t)(value2 - 1) == 0;
            negative1 = (uint8_t)(value2 - 1) & 0x80;
            overflow1 = ((x_ret ^ (uint16_t)(x_ret + 0x0200)) & ((uint16_t)(x_ret + 0x0200) ^ 0x0200) & 0x8000) != 0;
            direct_page = dp_ret;
            continue;
        }
        a1 = 0xFF;
        a_hi1 = (uint16_t)(x_ret + 0x0200) >> 8;
        x1 = (uint16_t)(x_ret + 0x0200);
        carry1 = x_ret + 0x0200 > 0xFFFF;
        zero1 = 0;
        negative1 = 1;
        overflow1 = ((x_ret ^ (uint16_t)(x_ret + 0x0200)) & ((uint16_t)(x_ret + 0x0200) ^ 0x0200) & 0x8000) != 0;
        direct_page = dp_ret;
        break;
    }
    RAM8(0x0000 + sp0 - 3) = a1;
    uint8_t value3 = RAM8(0x0000 + sp0 - 3);
    uint8_t value4 = RAM8(0x0000 + sp0 - 2);
    uint8_t value5 = RAM8(0x0000 + sp0 - 1);
    uint8_t value6 = RAM8(0x0000 + sp0);
    r->a = (a_hi1 << 8) | value3;
    r->y = y1;
    r->v = value4 & 0x40;
    r->mf = value4 & 0x20;
    r->xf = value4 & 0x10;
    r->db = 0x7E;
    r->dp = (value6 << 8) | value5;
    r->i = value4 & 0x04;
    r->d = value4 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC10A5A, SOM_RTS, "gen", find_first_eligible_hero_within_class_8, 0, L_A | L_Y | L_V, 4, 1, 0, 57, 32)
