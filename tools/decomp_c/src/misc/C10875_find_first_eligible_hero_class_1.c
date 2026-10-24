#include "som_c.h"

/* C10875 find_first_eligible_hero_class_1   [class B, 55 bytes, 31 instructions]
 * Source: src/rom/find_first_eligible_hero_class_1.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$01E1.  Callers read: AYV.
 */
static void find_first_eligible_hero_class_1(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x01E1) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 4) + 0x1 > 0x1FFF) { c->fail = 3; return; }
    uint8_t a_08a6 = 0;
    uint8_t a_hi_08a6 = 0;
    uint8_t y_08a6 = 0;
    uint16_t direct_page_08a6 = 0;
    uint8_t a_08a62 = 0;
    uint8_t a_hi_08a62 = 0;
    uint16_t y_08a62 = 0;
    uint16_t direct_page_08a62 = 0;
    RAM8(0x0000 + sp0) = 1;
    RAM8(0x0000 + sp0 - 1) = 0xE1;
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
    uint8_t width_pass = 0;
    for (;;) {
        if (width_pass == 0) {
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
            r->dp = (uint16_t)(sp0 - 4);
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR(c, 0x0887, 0xC1054A); GUARD_JSR(c, sp_call, 0x0887); } /* test_actor_target_eligibility */
            r->sp += 4;
            uint16_t dp_ret = r->dp;
            bool x_ret = r->xf;
            uint16_t x_ret2 = r->x;
            bool zero_ret = r->z;
            if (!zero_ret) {
                if (x_ret) {
                    uint8_t value = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
                    BUS8_SET(c, (uint16_t)(dp_ret + 1), (uint8_t)(value - 1));
                    if ((uint8_t)(value - 1) != 0) {
                        a1 = (uint8_t)((uint8_t)x_ret2 + 0x0200);
                        a_hi1 = (uint8_t)x_ret2 + 0x0200 >> 8;
                        x1 = (uint8_t)((uint8_t)x_ret2 + 0x0200);
                        y1 = (uint8_t)y1;
                        carry1 = (uint8_t)x_ret2 + 0x0200 > 0xFFFF;
                        zero1 = (uint8_t)(value - 1) == 0;
                        negative1 = (uint8_t)(value - 1) & 0x80;
                        overflow1 = (((uint8_t)x_ret2 ^ (uint8_t)x_ret2 + 0x0200) & ((uint8_t)x_ret2 + 0x0200 ^ 0x0200) & 0x8000) != 0;
                        direct_page = dp_ret;
                        width_pass = 2;
                        continue;
                    }
                    a_08a6 = 0xFF;
                    a_hi_08a6 = (uint8_t)x_ret2 + 0x0200 >> 8;
                    y_08a6 = (uint8_t)y1;
                    direct_page_08a6 = dp_ret;
                    goto shared_08A6;
                } else {
                    uint8_t value2 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
                    BUS8_SET(c, (uint16_t)(dp_ret + 1), (uint8_t)(value2 - 1));
                    if ((uint8_t)(value2 - 1) != 0) {
                        a1 = (uint8_t)(x_ret2 + 0x0200);
                        a_hi1 = (uint16_t)(x_ret2 + 0x0200) >> 8;
                        x1 = (uint16_t)(x_ret2 + 0x0200);
                        carry1 = x_ret2 + 0x0200 > 0xFFFF;
                        zero1 = (uint8_t)(value2 - 1) == 0;
                        negative1 = (uint8_t)(value2 - 1) & 0x80;
                        overflow1 = ((x_ret2 ^ (uint16_t)(x_ret2 + 0x0200)) & ((uint16_t)(x_ret2 + 0x0200) ^ 0x0200) & 0x8000) != 0;
                        direct_page = dp_ret;
                        continue;
                    }
                    a_08a62 = 0xFF;
                    a_hi_08a62 = (uint16_t)(x_ret2 + 0x0200) >> 8;
                    y_08a62 = y1;
                    direct_page_08a62 = dp_ret;
                    goto shared_08A6_1;
                }
            }
            r->mf = 1;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR(c, 0x088C, 0xC10358); GUARD_JSR(c, sp_call, 0x088C); } /* classify_actor_squared_distance */
            r->sp += 4;
            if (r->mf != 1) { c->fail = 3; return; }
            bool x_ret3 = r->xf;
            uint16_t a_all2 = r->a;
            if ((uint8_t)a_all2 == 1) {
                r->c = (uint8_t)a_all2 >= 1;
                r->z = (uint8_t)a_all2 == 1;
                r->n = (uint8_t)((uint8_t)a_all2 - 1) & 0x80;
                r->sp -= 4;
                { const uint16_t sp_call = r->sp; JSR(c, 0x08A5, 0xC105CF); GUARD_JSR(c, sp_call, 0x08A5); } /* actor_slot_from_address_high_byte */
                r->sp += 4;
                bool x_ret4 = r->xf;
                uint16_t a_all3 = r->a;
                if (x_ret4) {
                    a_08a6 = (uint8_t)a_all3;
                    a_hi_08a6 = a_all3 >> 8;
                    y_08a6 = (uint8_t)y1;
                    direct_page_08a6 = dp_ret;
                    goto shared_08A6;
                } else {
                    a_08a62 = (uint8_t)a_all3;
                    a_hi_08a62 = a_all3 >> 8;
                    y_08a62 = y1;
                    direct_page_08a62 = dp_ret;
                    goto shared_08A6_1;
                }
            }
            if (x_ret3) {
                uint8_t value3 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
                BUS8_SET(c, (uint16_t)(dp_ret + 1), (uint8_t)(value3 - 1));
                if ((uint8_t)(value3 - 1) != 0) {
                    a1 = (uint8_t)((uint8_t)x_ret2 + 0x0200);
                    a_hi1 = (uint8_t)x_ret2 + 0x0200 >> 8;
                    x1 = (uint8_t)((uint8_t)x_ret2 + 0x0200);
                    y1 = (uint8_t)y1;
                    carry1 = (uint8_t)x_ret2 + 0x0200 > 0xFFFF;
                    zero1 = (uint8_t)(value3 - 1) == 0;
                    negative1 = (uint8_t)(value3 - 1) & 0x80;
                    overflow1 = (((uint8_t)x_ret2 ^ (uint8_t)x_ret2 + 0x0200) & ((uint8_t)x_ret2 + 0x0200 ^ 0x0200) & 0x8000) != 0;
                    direct_page = dp_ret;
                    width_pass = 2;
                    continue;
                }
                a_08a6 = 0xFF;
                a_hi_08a6 = (uint8_t)x_ret2 + 0x0200 >> 8;
                y_08a6 = (uint8_t)y1;
                direct_page_08a6 = dp_ret;
                goto shared_08A6;
            } else {
                uint8_t value4 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
                BUS8_SET(c, (uint16_t)(dp_ret + 1), (uint8_t)(value4 - 1));
                if ((uint8_t)(value4 - 1) != 0) {
                    a1 = (uint8_t)(x_ret2 + 0x0200);
                    a_hi1 = (uint16_t)(x_ret2 + 0x0200) >> 8;
                    x1 = (uint16_t)(x_ret2 + 0x0200);
                    carry1 = x_ret2 + 0x0200 > 0xFFFF;
                    zero1 = (uint8_t)(value4 - 1) == 0;
                    negative1 = (uint8_t)(value4 - 1) & 0x80;
                    overflow1 = ((x_ret2 ^ (uint16_t)(x_ret2 + 0x0200)) & ((uint16_t)(x_ret2 + 0x0200) ^ 0x0200) & 0x8000) != 0;
                    direct_page = dp_ret;
                    continue;
                }
                a_08a62 = 0xFF;
                a_hi_08a62 = (uint16_t)(x_ret2 + 0x0200) >> 8;
                y_08a62 = y1;
                direct_page_08a62 = dp_ret;
                goto shared_08A6_1;
            }
        } else if (width_pass == 1) {
            r->a = (a_hi1 << 8) | a1;
            r->x = (uint8_t)x1;
            r->y = (uint8_t)y1;
            r->c = carry1;
            r->z = zero1;
            r->n = negative1;
            r->v = overflow1;
            r->mf = 1;
            r->xf = 1;
            r->db = 0x7E;
            r->dp = direct_page;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR(c, 0x0887, 0xC1054A); GUARD_JSR(c, sp_call, 0x0887); } /* test_actor_target_eligibility */
            r->sp += 4;
            uint16_t dp_ret2 = r->dp;
            bool x_ret5 = r->xf;
            uint16_t x_ret6 = r->x;
            bool zero_ret4 = r->z;
            if (!zero_ret4) {
                if (x_ret5) {
                    uint8_t value5 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 1));
                    BUS8_SET(c, (uint16_t)(dp_ret2 + 1), (uint8_t)(value5 - 1));
                    if ((uint8_t)(value5 - 1) != 0) {
                        a1 = (uint8_t)((uint8_t)x_ret6 + 0x0200);
                        a_hi1 = (uint8_t)x_ret6 + 0x0200 >> 8;
                        x1 = (uint8_t)((uint8_t)x_ret6 + 0x0200);
                        y1 = (uint8_t)y1;
                        carry1 = (uint8_t)x_ret6 + 0x0200 > 0xFFFF;
                        zero1 = (uint8_t)(value5 - 1) == 0;
                        negative1 = (uint8_t)(value5 - 1) & 0x80;
                        overflow1 = (((uint8_t)x_ret6 ^ (uint8_t)x_ret6 + 0x0200) & ((uint8_t)x_ret6 + 0x0200 ^ 0x0200) & 0x8000) != 0;
                        direct_page = dp_ret2;
                        continue;
                    }
                    a_08a6 = 0xFF;
                    a_hi_08a6 = (uint8_t)x_ret6 + 0x0200 >> 8;
                    y_08a6 = (uint8_t)y1;
                    direct_page_08a6 = dp_ret2;
                    goto shared_08A6;
                } else {
                    uint8_t value6 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 1));
                    BUS8_SET(c, (uint16_t)(dp_ret2 + 1), (uint8_t)(value6 - 1));
                    if ((uint8_t)(value6 - 1) != 0) {
                        a1 = (uint8_t)(x_ret6 + 0x0200);
                        a_hi1 = (uint16_t)(x_ret6 + 0x0200) >> 8;
                        x1 = (uint16_t)(x_ret6 + 0x0200);
                        y1 = (uint8_t)y1;
                        carry1 = x_ret6 + 0x0200 > 0xFFFF;
                        zero1 = (uint8_t)(value6 - 1) == 0;
                        negative1 = (uint8_t)(value6 - 1) & 0x80;
                        overflow1 = ((x_ret6 ^ (uint16_t)(x_ret6 + 0x0200)) & ((uint16_t)(x_ret6 + 0x0200) ^ 0x0200) & 0x8000) != 0;
                        direct_page = dp_ret2;
                        width_pass = 3;
                        continue;
                    }
                    a_08a62 = 0xFF;
                    a_hi_08a62 = (uint16_t)(x_ret6 + 0x0200) >> 8;
                    y_08a62 = (uint8_t)y1;
                    direct_page_08a62 = dp_ret2;
                    goto shared_08A6_1;
                }
            }
            r->mf = 1;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR(c, 0x088C, 0xC10358); GUARD_JSR(c, sp_call, 0x088C); } /* classify_actor_squared_distance */
            r->sp += 4;
            if (r->mf != 1) { c->fail = 3; return; }
            bool x_ret7 = r->xf;
            uint16_t a_all5 = r->a;
            if ((uint8_t)a_all5 == 1) {
                r->c = (uint8_t)a_all5 >= 1;
                r->z = (uint8_t)a_all5 == 1;
                r->n = (uint8_t)((uint8_t)a_all5 - 1) & 0x80;
                r->sp -= 4;
                { const uint16_t sp_call = r->sp; JSR(c, 0x08A5, 0xC105CF); GUARD_JSR(c, sp_call, 0x08A5); } /* actor_slot_from_address_high_byte */
                r->sp += 4;
                bool x_ret8 = r->xf;
                uint16_t a_all6 = r->a;
                if (x_ret8) {
                    a_08a6 = (uint8_t)a_all6;
                    a_hi_08a6 = a_all6 >> 8;
                    y_08a6 = (uint8_t)y1;
                    direct_page_08a6 = dp_ret2;
                    goto shared_08A6;
                } else {
                    a_08a62 = (uint8_t)a_all6;
                    a_hi_08a62 = a_all6 >> 8;
                    y_08a62 = (uint8_t)y1;
                    direct_page_08a62 = dp_ret2;
                    goto shared_08A6_1;
                }
            }
            if (x_ret7) {
                uint8_t value7 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 1));
                BUS8_SET(c, (uint16_t)(dp_ret2 + 1), (uint8_t)(value7 - 1));
                if ((uint8_t)(value7 - 1) != 0) {
                    a1 = (uint8_t)((uint8_t)x_ret6 + 0x0200);
                    a_hi1 = (uint8_t)x_ret6 + 0x0200 >> 8;
                    x1 = (uint8_t)((uint8_t)x_ret6 + 0x0200);
                    y1 = (uint8_t)y1;
                    carry1 = (uint8_t)x_ret6 + 0x0200 > 0xFFFF;
                    zero1 = (uint8_t)(value7 - 1) == 0;
                    negative1 = (uint8_t)(value7 - 1) & 0x80;
                    overflow1 = (((uint8_t)x_ret6 ^ (uint8_t)x_ret6 + 0x0200) & ((uint8_t)x_ret6 + 0x0200 ^ 0x0200) & 0x8000) != 0;
                    direct_page = dp_ret2;
                    continue;
                }
                a_08a6 = 0xFF;
                a_hi_08a6 = (uint8_t)x_ret6 + 0x0200 >> 8;
                y_08a6 = (uint8_t)y1;
                direct_page_08a6 = dp_ret2;
                goto shared_08A6;
            } else {
                uint8_t value8 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 1));
                BUS8_SET(c, (uint16_t)(dp_ret2 + 1), (uint8_t)(value8 - 1));
                if ((uint8_t)(value8 - 1) != 0) {
                    a1 = (uint8_t)(x_ret6 + 0x0200);
                    a_hi1 = (uint16_t)(x_ret6 + 0x0200) >> 8;
                    x1 = (uint16_t)(x_ret6 + 0x0200);
                    y1 = (uint8_t)y1;
                    carry1 = x_ret6 + 0x0200 > 0xFFFF;
                    zero1 = (uint8_t)(value8 - 1) == 0;
                    negative1 = (uint8_t)(value8 - 1) & 0x80;
                    overflow1 = ((x_ret6 ^ (uint16_t)(x_ret6 + 0x0200)) & ((uint16_t)(x_ret6 + 0x0200) ^ 0x0200) & 0x8000) != 0;
                    direct_page = dp_ret2;
                    width_pass = 3;
                    continue;
                }
                a_08a62 = 0xFF;
                a_hi_08a62 = (uint16_t)(x_ret6 + 0x0200) >> 8;
                y_08a62 = (uint8_t)y1;
                direct_page_08a62 = dp_ret2;
                goto shared_08A6_1;
            }
        } else if (width_pass == 2) {
            r->a = (a_hi1 << 8) | a1;
            r->x = (uint8_t)x1;
            r->y = (uint8_t)y1;
            r->c = carry1;
            r->z = zero1;
            r->n = negative1;
            r->v = overflow1;
            r->mf = 1;
            r->xf = 1;
            r->db = 0x7E;
            r->dp = (uint16_t)(sp0 - 4);
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR(c, 0x0887, 0xC1054A); GUARD_JSR(c, sp_call, 0x0887); } /* test_actor_target_eligibility */
            r->sp += 4;
            uint16_t dp_ret3 = r->dp;
            bool x_ret9 = r->xf;
            uint16_t x_ret10 = r->x;
            bool zero_ret7 = r->z;
            if (!zero_ret7) {
                if (x_ret9) {
                    uint8_t value9 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 1));
                    BUS8_SET(c, (uint16_t)(dp_ret3 + 1), (uint8_t)(value9 - 1));
                    if ((uint8_t)(value9 - 1) != 0) {
                        a1 = (uint8_t)((uint8_t)x_ret10 + 0x0200);
                        a_hi1 = (uint8_t)x_ret10 + 0x0200 >> 8;
                        x1 = (uint8_t)((uint8_t)x_ret10 + 0x0200);
                        y1 = (uint8_t)y1;
                        carry1 = (uint8_t)x_ret10 + 0x0200 > 0xFFFF;
                        zero1 = (uint8_t)(value9 - 1) == 0;
                        negative1 = (uint8_t)(value9 - 1) & 0x80;
                        overflow1 = (((uint8_t)x_ret10 ^ (uint8_t)x_ret10 + 0x0200) & ((uint8_t)x_ret10 + 0x0200 ^ 0x0200) & 0x8000) != 0;
                        direct_page = dp_ret3;
                        continue;
                    }
                    a_08a6 = 0xFF;
                    a_hi_08a6 = (uint8_t)x_ret10 + 0x0200 >> 8;
                    y_08a6 = (uint8_t)y1;
                    direct_page_08a6 = dp_ret3;
                    goto shared_08A6;
                } else {
                    uint8_t value10 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 1));
                    BUS8_SET(c, (uint16_t)(dp_ret3 + 1), (uint8_t)(value10 - 1));
                    if ((uint8_t)(value10 - 1) != 0) {
                        a1 = (uint8_t)(x_ret10 + 0x0200);
                        a_hi1 = (uint16_t)(x_ret10 + 0x0200) >> 8;
                        x1 = (uint16_t)(x_ret10 + 0x0200);
                        y1 = (uint8_t)y1;
                        carry1 = x_ret10 + 0x0200 > 0xFFFF;
                        zero1 = (uint8_t)(value10 - 1) == 0;
                        negative1 = (uint8_t)(value10 - 1) & 0x80;
                        overflow1 = ((x_ret10 ^ (uint16_t)(x_ret10 + 0x0200)) & ((uint16_t)(x_ret10 + 0x0200) ^ 0x0200) & 0x8000) != 0;
                        direct_page = dp_ret3;
                        width_pass = 0;
                        continue;
                    }
                    a_08a62 = 0xFF;
                    a_hi_08a62 = (uint16_t)(x_ret10 + 0x0200) >> 8;
                    y_08a62 = (uint8_t)y1;
                    direct_page_08a62 = dp_ret3;
                    goto shared_08A6_1;
                }
            }
            r->mf = 1;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR(c, 0x088C, 0xC10358); GUARD_JSR(c, sp_call, 0x088C); } /* classify_actor_squared_distance */
            r->sp += 4;
            if (r->mf != 1) { c->fail = 3; return; }
            bool x_ret11 = r->xf;
            uint16_t a_all8 = r->a;
            if ((uint8_t)a_all8 == 1) {
                r->c = (uint8_t)a_all8 >= 1;
                r->z = (uint8_t)a_all8 == 1;
                r->n = (uint8_t)((uint8_t)a_all8 - 1) & 0x80;
                r->sp -= 4;
                { const uint16_t sp_call = r->sp; JSR(c, 0x08A5, 0xC105CF); GUARD_JSR(c, sp_call, 0x08A5); } /* actor_slot_from_address_high_byte */
                r->sp += 4;
                bool x_ret12 = r->xf;
                uint16_t a_all9 = r->a;
                if (x_ret12) {
                    a_08a6 = (uint8_t)a_all9;
                    a_hi_08a6 = a_all9 >> 8;
                    y_08a6 = (uint8_t)y1;
                    direct_page_08a6 = dp_ret3;
                    goto shared_08A6;
                } else {
                    a_08a62 = (uint8_t)a_all9;
                    a_hi_08a62 = a_all9 >> 8;
                    y_08a62 = (uint8_t)y1;
                    direct_page_08a62 = dp_ret3;
                    goto shared_08A6_1;
                }
            }
            if (x_ret11) {
                uint8_t value11 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 1));
                BUS8_SET(c, (uint16_t)(dp_ret3 + 1), (uint8_t)(value11 - 1));
                if ((uint8_t)(value11 - 1) != 0) {
                    a1 = (uint8_t)((uint8_t)x_ret10 + 0x0200);
                    a_hi1 = (uint8_t)x_ret10 + 0x0200 >> 8;
                    x1 = (uint8_t)((uint8_t)x_ret10 + 0x0200);
                    y1 = (uint8_t)y1;
                    carry1 = (uint8_t)x_ret10 + 0x0200 > 0xFFFF;
                    zero1 = (uint8_t)(value11 - 1) == 0;
                    negative1 = (uint8_t)(value11 - 1) & 0x80;
                    overflow1 = (((uint8_t)x_ret10 ^ (uint8_t)x_ret10 + 0x0200) & ((uint8_t)x_ret10 + 0x0200 ^ 0x0200) & 0x8000) != 0;
                    direct_page = dp_ret3;
                    continue;
                }
                a_08a6 = 0xFF;
                a_hi_08a6 = (uint8_t)x_ret10 + 0x0200 >> 8;
                y_08a6 = (uint8_t)y1;
                direct_page_08a6 = dp_ret3;
                goto shared_08A6;
            } else {
                uint8_t value12 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 1));
                BUS8_SET(c, (uint16_t)(dp_ret3 + 1), (uint8_t)(value12 - 1));
                if ((uint8_t)(value12 - 1) != 0) {
                    a1 = (uint8_t)(x_ret10 + 0x0200);
                    a_hi1 = (uint16_t)(x_ret10 + 0x0200) >> 8;
                    x1 = (uint16_t)(x_ret10 + 0x0200);
                    y1 = (uint8_t)y1;
                    carry1 = x_ret10 + 0x0200 > 0xFFFF;
                    zero1 = (uint8_t)(value12 - 1) == 0;
                    negative1 = (uint8_t)(value12 - 1) & 0x80;
                    overflow1 = ((x_ret10 ^ (uint16_t)(x_ret10 + 0x0200)) & ((uint16_t)(x_ret10 + 0x0200) ^ 0x0200) & 0x8000) != 0;
                    direct_page = dp_ret3;
                    width_pass = 0;
                    continue;
                }
                a_08a62 = 0xFF;
                a_hi_08a62 = (uint16_t)(x_ret10 + 0x0200) >> 8;
                y_08a62 = (uint8_t)y1;
                direct_page_08a62 = dp_ret3;
                goto shared_08A6_1;
            }
        } else {
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
            { const uint16_t sp_call = r->sp; JSR(c, 0x0887, 0xC1054A); GUARD_JSR(c, sp_call, 0x0887); } /* test_actor_target_eligibility */
            r->sp += 4;
            uint16_t dp_ret4 = r->dp;
            bool x_ret13 = r->xf;
            uint16_t x_ret14 = r->x;
            bool zero_ret10 = r->z;
            if (!zero_ret10) {
                if (x_ret13) {
                    uint8_t value13 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 1));
                    BUS8_SET(c, (uint16_t)(dp_ret4 + 1), (uint8_t)(value13 - 1));
                    if ((uint8_t)(value13 - 1) != 0) {
                        a1 = (uint8_t)((uint8_t)x_ret14 + 0x0200);
                        a_hi1 = (uint8_t)x_ret14 + 0x0200 >> 8;
                        x1 = (uint8_t)((uint8_t)x_ret14 + 0x0200);
                        y1 = (uint8_t)y1;
                        carry1 = (uint8_t)x_ret14 + 0x0200 > 0xFFFF;
                        zero1 = (uint8_t)(value13 - 1) == 0;
                        negative1 = (uint8_t)(value13 - 1) & 0x80;
                        overflow1 = (((uint8_t)x_ret14 ^ (uint8_t)x_ret14 + 0x0200) & ((uint8_t)x_ret14 + 0x0200 ^ 0x0200) & 0x8000) != 0;
                        direct_page = dp_ret4;
                        width_pass = 1;
                        continue;
                    }
                    a_08a6 = 0xFF;
                    a_hi_08a6 = (uint8_t)x_ret14 + 0x0200 >> 8;
                    y_08a6 = (uint8_t)y1;
                    direct_page_08a6 = dp_ret4;
                    goto shared_08A6;
                } else {
                    uint8_t value14 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 1));
                    BUS8_SET(c, (uint16_t)(dp_ret4 + 1), (uint8_t)(value14 - 1));
                    if ((uint8_t)(value14 - 1) != 0) {
                        a1 = (uint8_t)(x_ret14 + 0x0200);
                        a_hi1 = (uint16_t)(x_ret14 + 0x0200) >> 8;
                        x1 = (uint16_t)(x_ret14 + 0x0200);
                        carry1 = x_ret14 + 0x0200 > 0xFFFF;
                        zero1 = (uint8_t)(value14 - 1) == 0;
                        negative1 = (uint8_t)(value14 - 1) & 0x80;
                        overflow1 = ((x_ret14 ^ (uint16_t)(x_ret14 + 0x0200)) & ((uint16_t)(x_ret14 + 0x0200) ^ 0x0200) & 0x8000) != 0;
                        direct_page = dp_ret4;
                        continue;
                    }
                    a_08a62 = 0xFF;
                    a_hi_08a62 = (uint16_t)(x_ret14 + 0x0200) >> 8;
                    y_08a62 = y1;
                    direct_page_08a62 = dp_ret4;
                    goto shared_08A6_1;
                }
            }
            r->mf = 1;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR(c, 0x088C, 0xC10358); GUARD_JSR(c, sp_call, 0x088C); } /* classify_actor_squared_distance */
            r->sp += 4;
            if (r->mf != 1) { c->fail = 3; return; }
            bool x_ret15 = r->xf;
            uint16_t a_all11 = r->a;
            if ((uint8_t)a_all11 == 1) {
                r->c = (uint8_t)a_all11 >= 1;
                r->z = (uint8_t)a_all11 == 1;
                r->n = (uint8_t)((uint8_t)a_all11 - 1) & 0x80;
                r->sp -= 4;
                { const uint16_t sp_call = r->sp; JSR(c, 0x08A5, 0xC105CF); GUARD_JSR(c, sp_call, 0x08A5); } /* actor_slot_from_address_high_byte */
                r->sp += 4;
                bool x_ret16 = r->xf;
                uint16_t a_all12 = r->a;
                if (x_ret16) {
                    a_08a6 = (uint8_t)a_all12;
                    a_hi_08a6 = a_all12 >> 8;
                    y_08a6 = (uint8_t)y1;
                    direct_page_08a6 = dp_ret4;
                    goto shared_08A6;
                } else {
                    a_08a62 = (uint8_t)a_all12;
                    a_hi_08a62 = a_all12 >> 8;
                    y_08a62 = y1;
                    direct_page_08a62 = dp_ret4;
                    goto shared_08A6_1;
                }
            }
            if (x_ret15) {
                uint8_t value15 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 1));
                BUS8_SET(c, (uint16_t)(dp_ret4 + 1), (uint8_t)(value15 - 1));
                if ((uint8_t)(value15 - 1) != 0) {
                    a1 = (uint8_t)((uint8_t)x_ret14 + 0x0200);
                    a_hi1 = (uint8_t)x_ret14 + 0x0200 >> 8;
                    x1 = (uint8_t)((uint8_t)x_ret14 + 0x0200);
                    y1 = (uint8_t)y1;
                    carry1 = (uint8_t)x_ret14 + 0x0200 > 0xFFFF;
                    zero1 = (uint8_t)(value15 - 1) == 0;
                    negative1 = (uint8_t)(value15 - 1) & 0x80;
                    overflow1 = (((uint8_t)x_ret14 ^ (uint8_t)x_ret14 + 0x0200) & ((uint8_t)x_ret14 + 0x0200 ^ 0x0200) & 0x8000) != 0;
                    direct_page = dp_ret4;
                    width_pass = 1;
                    continue;
                }
                a_08a6 = 0xFF;
                a_hi_08a6 = (uint8_t)x_ret14 + 0x0200 >> 8;
                y_08a6 = (uint8_t)y1;
                direct_page_08a6 = dp_ret4;
                goto shared_08A6;
            } else {
                uint8_t value16 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 1));
                BUS8_SET(c, (uint16_t)(dp_ret4 + 1), (uint8_t)(value16 - 1));
                if ((uint8_t)(value16 - 1) != 0) {
                    a1 = (uint8_t)(x_ret14 + 0x0200);
                    a_hi1 = (uint16_t)(x_ret14 + 0x0200) >> 8;
                    x1 = (uint16_t)(x_ret14 + 0x0200);
                    carry1 = x_ret14 + 0x0200 > 0xFFFF;
                    zero1 = (uint8_t)(value16 - 1) == 0;
                    negative1 = (uint8_t)(value16 - 1) & 0x80;
                    overflow1 = ((x_ret14 ^ (uint16_t)(x_ret14 + 0x0200)) & ((uint16_t)(x_ret14 + 0x0200) ^ 0x0200) & 0x8000) != 0;
                    direct_page = dp_ret4;
                    continue;
                }
                a_08a62 = 0xFF;
                a_hi_08a62 = (uint16_t)(x_ret14 + 0x0200) >> 8;
                y_08a62 = y1;
                direct_page_08a62 = dp_ret4;
                goto shared_08A6_1;
            }
        }
    }
    shared_08A6:;
    RAM8(0x0000 + sp0 - 3) = (uint8_t)a_08a6;
    uint8_t value17 = RAM8(0x0000 + sp0 - 3);
    uint8_t value18 = RAM8(0x0000 + sp0 - 2);
    uint8_t value19 = RAM8(0x0000 + sp0 - 1);
    uint8_t value20 = RAM8(0x0000 + sp0);
    r->a = (a_hi_08a6 << 8) | value17;
    r->y = y_08a6;
    r->v = value18 & 0x40;
    r->mf = value18 & 0x20;
    r->xf = value18 & 0x10;
    r->db = 0x7E;
    r->dp = (value20 << 8) | value19;
    r->i = value18 & 0x04;
    r->d = value18 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
    shared_08A6_1:;
    RAM8(0x0000 + sp0 - 3) = (uint8_t)a_08a62;
    uint8_t value21 = RAM8(0x0000 + sp0 - 3);
    uint8_t value22 = RAM8(0x0000 + sp0 - 2);
    uint8_t value23 = RAM8(0x0000 + sp0 - 1);
    uint8_t value24 = RAM8(0x0000 + sp0);
    r->a = (a_hi_08a62 << 8) | value21;
    r->y = y_08a62;
    r->v = value22 & 0x40;
    r->mf = value22 & 0x20;
    r->xf = value22 & 0x10;
    r->db = 0x7E;
    r->dp = (value24 << 8) | value23;
    r->i = value22 & 0x04;
    r->d = value22 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC10875, SOM_RTS, "gen", find_first_eligible_hero_class_1, 0, L_A | L_Y | L_V, 4, 1, 0, 55, 31)
