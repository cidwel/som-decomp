#include "som_c.h"

/* C10CE3 find_first_eligible_ally_below_class_32   [class B, 61 bytes, 34 instructions]
 * Source: src/rom/find_first_eligible_ally_below_class_32.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: AYV.
 */
static void find_first_eligible_ally_below_class_32(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 4) + 0x1 > 0x1FFF) { c->fail = 3; return; }
    uint8_t a_0d1a = 0;
    uint8_t a_hi_0d1a = 0;
    uint8_t y_0d1a = 0;
    uint16_t direct_page_0d1a = 0;
    uint8_t a_0d1a2 = 0;
    uint8_t a_hi_0d1a2 = 0;
    uint16_t y_0d1a2 = 0;
    uint16_t direct_page_0d1a2 = 0;
    uint8_t a_0d17 = 0;
    uint8_t a_hi_0d17 = 0;
    uint8_t x_0d17 = 0;
    uint8_t y_0d17 = 0;
    uint16_t direct_page_0d17 = 0;
    uint8_t a_0d172 = 0;
    uint8_t a_hi_0d172 = 0;
    uint16_t x_0d172 = 0;
    uint16_t y_0d172 = 0;
    uint16_t direct_page_0d172 = 0;
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7E;
    RAM8(0x0001 + (uint16_t)(sp0 - 4)) = 3;
    uint8_t a1 = 3;
    uint8_t a_hi1 = (uint16_t)(sp0 - 4) >> 8;
    uint16_t x1 = 0xE600;
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
            { const uint16_t sp_call = r->sp; JSR(c, 0x0CF5, 0xC1058B); GUARD_JSR(c, sp_call, 0x0CF5); } /* reject_ineligible_or_nonmonster_actor */
            r->sp += 4;
            uint16_t dp_ret = r->dp;
            bool x_ret = r->xf;
            uint16_t x_ret2 = r->x;
            bool carry_ret = r->c;
            if (carry_ret) {
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
                    a_0d1a = 0xFF;
                    a_hi_0d1a = (uint8_t)x_ret2 + 0x0200 >> 8;
                    y_0d1a = (uint8_t)y1;
                    direct_page_0d1a = dp_ret;
                    goto shared_0D1A;
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
                    a_0d1a2 = 0xFF;
                    a_hi_0d1a2 = (uint16_t)(x_ret2 + 0x0200) >> 8;
                    y_0d1a2 = y1;
                    direct_page_0d1a2 = dp_ret;
                    goto shared_0D1A_1;
                }
            }
            r->mf = 1;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR(c, 0x0CFA, 0xC10358); GUARD_JSR(c, sp_call, 0x0CFA); } /* classify_actor_squared_distance */
            r->sp += 4;
            if (r->mf != 1) { c->fail = 3; return; }
            bool x_ret3 = r->xf;
            uint16_t a_all2 = r->a;
            bool overflow_ret2 = r->v;
            if ((uint8_t)((uint8_t)a_all2 - 0x20) & 0x80) {
                if (!overflow_ret2) {
                    if (x_ret3) {
                        a_0d17 = (uint8_t)a_all2;
                        a_hi_0d17 = a_all2 >> 8;
                        x_0d17 = (uint8_t)x_ret2;
                        y_0d17 = (uint8_t)y1;
                        direct_page_0d17 = dp_ret;
                        goto shared_0D17;
                    } else {
                        a_0d172 = (uint8_t)a_all2;
                        a_hi_0d172 = a_all2 >> 8;
                        x_0d172 = x_ret2;
                        y_0d172 = y1;
                        direct_page_0d172 = dp_ret;
                        goto shared_0D17_1;
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
                    a_0d1a = 0xFF;
                    a_hi_0d1a = (uint8_t)x_ret2 + 0x0200 >> 8;
                    y_0d1a = (uint8_t)y1;
                    direct_page_0d1a = dp_ret;
                    goto shared_0D1A;
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
                    a_0d1a2 = 0xFF;
                    a_hi_0d1a2 = (uint16_t)(x_ret2 + 0x0200) >> 8;
                    y_0d1a2 = y1;
                    direct_page_0d1a2 = dp_ret;
                    goto shared_0D1A_1;
                }
            }
            if (overflow_ret2) {
                if (x_ret3) {
                    a_0d17 = (uint8_t)a_all2;
                    a_hi_0d17 = a_all2 >> 8;
                    x_0d17 = (uint8_t)x_ret2;
                    y_0d17 = (uint8_t)y1;
                    direct_page_0d17 = dp_ret;
                    goto shared_0D17;
                } else {
                    a_0d172 = (uint8_t)a_all2;
                    a_hi_0d172 = a_all2 >> 8;
                    x_0d172 = x_ret2;
                    y_0d172 = y1;
                    direct_page_0d172 = dp_ret;
                    goto shared_0D17_1;
                }
            }
            if (x_ret3) {
                uint8_t value5 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
                BUS8_SET(c, (uint16_t)(dp_ret + 1), (uint8_t)(value5 - 1));
                if ((uint8_t)(value5 - 1) != 0) {
                    a1 = (uint8_t)((uint8_t)x_ret2 + 0x0200);
                    a_hi1 = (uint8_t)x_ret2 + 0x0200 >> 8;
                    x1 = (uint8_t)((uint8_t)x_ret2 + 0x0200);
                    y1 = (uint8_t)y1;
                    carry1 = (uint8_t)x_ret2 + 0x0200 > 0xFFFF;
                    zero1 = (uint8_t)(value5 - 1) == 0;
                    negative1 = (uint8_t)(value5 - 1) & 0x80;
                    overflow1 = (((uint8_t)x_ret2 ^ (uint8_t)x_ret2 + 0x0200) & ((uint8_t)x_ret2 + 0x0200 ^ 0x0200) & 0x8000) != 0;
                    direct_page = dp_ret;
                    width_pass = 2;
                    continue;
                }
                a_0d1a = 0xFF;
                a_hi_0d1a = (uint8_t)x_ret2 + 0x0200 >> 8;
                y_0d1a = (uint8_t)y1;
                direct_page_0d1a = dp_ret;
                goto shared_0D1A;
            } else {
                uint8_t value6 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
                BUS8_SET(c, (uint16_t)(dp_ret + 1), (uint8_t)(value6 - 1));
                if ((uint8_t)(value6 - 1) != 0) {
                    a1 = (uint8_t)(x_ret2 + 0x0200);
                    a_hi1 = (uint16_t)(x_ret2 + 0x0200) >> 8;
                    x1 = (uint16_t)(x_ret2 + 0x0200);
                    carry1 = x_ret2 + 0x0200 > 0xFFFF;
                    zero1 = (uint8_t)(value6 - 1) == 0;
                    negative1 = (uint8_t)(value6 - 1) & 0x80;
                    overflow1 = ((x_ret2 ^ (uint16_t)(x_ret2 + 0x0200)) & ((uint16_t)(x_ret2 + 0x0200) ^ 0x0200) & 0x8000) != 0;
                    direct_page = dp_ret;
                    continue;
                }
                a_0d1a2 = 0xFF;
                a_hi_0d1a2 = (uint16_t)(x_ret2 + 0x0200) >> 8;
                y_0d1a2 = y1;
                direct_page_0d1a2 = dp_ret;
                goto shared_0D1A_1;
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
            { const uint16_t sp_call = r->sp; JSR(c, 0x0CF5, 0xC1058B); GUARD_JSR(c, sp_call, 0x0CF5); } /* reject_ineligible_or_nonmonster_actor */
            r->sp += 4;
            uint16_t dp_ret2 = r->dp;
            bool x_ret4 = r->xf;
            uint16_t x_ret5 = r->x;
            bool carry_ret3 = r->c;
            if (carry_ret3) {
                if (x_ret4) {
                    uint8_t value7 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 1));
                    BUS8_SET(c, (uint16_t)(dp_ret2 + 1), (uint8_t)(value7 - 1));
                    if ((uint8_t)(value7 - 1) != 0) {
                        a1 = (uint8_t)((uint8_t)x_ret5 + 0x0200);
                        a_hi1 = (uint8_t)x_ret5 + 0x0200 >> 8;
                        x1 = (uint8_t)((uint8_t)x_ret5 + 0x0200);
                        y1 = (uint8_t)y1;
                        carry1 = (uint8_t)x_ret5 + 0x0200 > 0xFFFF;
                        zero1 = (uint8_t)(value7 - 1) == 0;
                        negative1 = (uint8_t)(value7 - 1) & 0x80;
                        overflow1 = (((uint8_t)x_ret5 ^ (uint8_t)x_ret5 + 0x0200) & ((uint8_t)x_ret5 + 0x0200 ^ 0x0200) & 0x8000) != 0;
                        direct_page = dp_ret2;
                        continue;
                    }
                    a_0d1a = 0xFF;
                    a_hi_0d1a = (uint8_t)x_ret5 + 0x0200 >> 8;
                    y_0d1a = (uint8_t)y1;
                    direct_page_0d1a = dp_ret2;
                    goto shared_0D1A;
                } else {
                    uint8_t value8 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 1));
                    BUS8_SET(c, (uint16_t)(dp_ret2 + 1), (uint8_t)(value8 - 1));
                    if ((uint8_t)(value8 - 1) != 0) {
                        a1 = (uint8_t)(x_ret5 + 0x0200);
                        a_hi1 = (uint16_t)(x_ret5 + 0x0200) >> 8;
                        x1 = (uint16_t)(x_ret5 + 0x0200);
                        y1 = (uint8_t)y1;
                        carry1 = x_ret5 + 0x0200 > 0xFFFF;
                        zero1 = (uint8_t)(value8 - 1) == 0;
                        negative1 = (uint8_t)(value8 - 1) & 0x80;
                        overflow1 = ((x_ret5 ^ (uint16_t)(x_ret5 + 0x0200)) & ((uint16_t)(x_ret5 + 0x0200) ^ 0x0200) & 0x8000) != 0;
                        direct_page = dp_ret2;
                        width_pass = 3;
                        continue;
                    }
                    a_0d1a2 = 0xFF;
                    a_hi_0d1a2 = (uint16_t)(x_ret5 + 0x0200) >> 8;
                    y_0d1a2 = (uint8_t)y1;
                    direct_page_0d1a2 = dp_ret2;
                    goto shared_0D1A_1;
                }
            }
            r->mf = 1;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR(c, 0x0CFA, 0xC10358); GUARD_JSR(c, sp_call, 0x0CFA); } /* classify_actor_squared_distance */
            r->sp += 4;
            if (r->mf != 1) { c->fail = 3; return; }
            bool x_ret6 = r->xf;
            uint16_t a_all4 = r->a;
            bool overflow_ret4 = r->v;
            if ((uint8_t)((uint8_t)a_all4 - 0x20) & 0x80) {
                if (!overflow_ret4) {
                    if (x_ret6) {
                        a_0d17 = (uint8_t)a_all4;
                        a_hi_0d17 = a_all4 >> 8;
                        x_0d17 = (uint8_t)x_ret5;
                        y_0d17 = (uint8_t)y1;
                        direct_page_0d17 = dp_ret2;
                        goto shared_0D17;
                    } else {
                        a_0d172 = (uint8_t)a_all4;
                        a_hi_0d172 = a_all4 >> 8;
                        x_0d172 = x_ret5;
                        y_0d172 = (uint8_t)y1;
                        direct_page_0d172 = dp_ret2;
                        goto shared_0D17_1;
                    }
                }
                if (x_ret6) {
                    uint8_t value9 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 1));
                    BUS8_SET(c, (uint16_t)(dp_ret2 + 1), (uint8_t)(value9 - 1));
                    if ((uint8_t)(value9 - 1) != 0) {
                        a1 = (uint8_t)((uint8_t)x_ret5 + 0x0200);
                        a_hi1 = (uint8_t)x_ret5 + 0x0200 >> 8;
                        x1 = (uint8_t)((uint8_t)x_ret5 + 0x0200);
                        y1 = (uint8_t)y1;
                        carry1 = (uint8_t)x_ret5 + 0x0200 > 0xFFFF;
                        zero1 = (uint8_t)(value9 - 1) == 0;
                        negative1 = (uint8_t)(value9 - 1) & 0x80;
                        overflow1 = (((uint8_t)x_ret5 ^ (uint8_t)x_ret5 + 0x0200) & ((uint8_t)x_ret5 + 0x0200 ^ 0x0200) & 0x8000) != 0;
                        direct_page = dp_ret2;
                        continue;
                    }
                    a_0d1a = 0xFF;
                    a_hi_0d1a = (uint8_t)x_ret5 + 0x0200 >> 8;
                    y_0d1a = (uint8_t)y1;
                    direct_page_0d1a = dp_ret2;
                    goto shared_0D1A;
                } else {
                    uint8_t value10 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 1));
                    BUS8_SET(c, (uint16_t)(dp_ret2 + 1), (uint8_t)(value10 - 1));
                    if ((uint8_t)(value10 - 1) != 0) {
                        a1 = (uint8_t)(x_ret5 + 0x0200);
                        a_hi1 = (uint16_t)(x_ret5 + 0x0200) >> 8;
                        x1 = (uint16_t)(x_ret5 + 0x0200);
                        y1 = (uint8_t)y1;
                        carry1 = x_ret5 + 0x0200 > 0xFFFF;
                        zero1 = (uint8_t)(value10 - 1) == 0;
                        negative1 = (uint8_t)(value10 - 1) & 0x80;
                        overflow1 = ((x_ret5 ^ (uint16_t)(x_ret5 + 0x0200)) & ((uint16_t)(x_ret5 + 0x0200) ^ 0x0200) & 0x8000) != 0;
                        direct_page = dp_ret2;
                        width_pass = 3;
                        continue;
                    }
                    a_0d1a2 = 0xFF;
                    a_hi_0d1a2 = (uint16_t)(x_ret5 + 0x0200) >> 8;
                    y_0d1a2 = (uint8_t)y1;
                    direct_page_0d1a2 = dp_ret2;
                    goto shared_0D1A_1;
                }
            }
            if (overflow_ret4) {
                if (x_ret6) {
                    a_0d17 = (uint8_t)a_all4;
                    a_hi_0d17 = a_all4 >> 8;
                    x_0d17 = (uint8_t)x_ret5;
                    y_0d17 = (uint8_t)y1;
                    direct_page_0d17 = dp_ret2;
                    goto shared_0D17;
                } else {
                    a_0d172 = (uint8_t)a_all4;
                    a_hi_0d172 = a_all4 >> 8;
                    x_0d172 = x_ret5;
                    y_0d172 = (uint8_t)y1;
                    direct_page_0d172 = dp_ret2;
                    goto shared_0D17_1;
                }
            }
            if (x_ret6) {
                uint8_t value11 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 1));
                BUS8_SET(c, (uint16_t)(dp_ret2 + 1), (uint8_t)(value11 - 1));
                if ((uint8_t)(value11 - 1) != 0) {
                    a1 = (uint8_t)((uint8_t)x_ret5 + 0x0200);
                    a_hi1 = (uint8_t)x_ret5 + 0x0200 >> 8;
                    x1 = (uint8_t)((uint8_t)x_ret5 + 0x0200);
                    y1 = (uint8_t)y1;
                    carry1 = (uint8_t)x_ret5 + 0x0200 > 0xFFFF;
                    zero1 = (uint8_t)(value11 - 1) == 0;
                    negative1 = (uint8_t)(value11 - 1) & 0x80;
                    overflow1 = (((uint8_t)x_ret5 ^ (uint8_t)x_ret5 + 0x0200) & ((uint8_t)x_ret5 + 0x0200 ^ 0x0200) & 0x8000) != 0;
                    direct_page = dp_ret2;
                    continue;
                }
                a_0d1a = 0xFF;
                a_hi_0d1a = (uint8_t)x_ret5 + 0x0200 >> 8;
                y_0d1a = (uint8_t)y1;
                direct_page_0d1a = dp_ret2;
                goto shared_0D1A;
            } else {
                uint8_t value12 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 1));
                BUS8_SET(c, (uint16_t)(dp_ret2 + 1), (uint8_t)(value12 - 1));
                if ((uint8_t)(value12 - 1) != 0) {
                    a1 = (uint8_t)(x_ret5 + 0x0200);
                    a_hi1 = (uint16_t)(x_ret5 + 0x0200) >> 8;
                    x1 = (uint16_t)(x_ret5 + 0x0200);
                    y1 = (uint8_t)y1;
                    carry1 = x_ret5 + 0x0200 > 0xFFFF;
                    zero1 = (uint8_t)(value12 - 1) == 0;
                    negative1 = (uint8_t)(value12 - 1) & 0x80;
                    overflow1 = ((x_ret5 ^ (uint16_t)(x_ret5 + 0x0200)) & ((uint16_t)(x_ret5 + 0x0200) ^ 0x0200) & 0x8000) != 0;
                    direct_page = dp_ret2;
                    width_pass = 3;
                    continue;
                }
                a_0d1a2 = 0xFF;
                a_hi_0d1a2 = (uint16_t)(x_ret5 + 0x0200) >> 8;
                y_0d1a2 = (uint8_t)y1;
                direct_page_0d1a2 = dp_ret2;
                goto shared_0D1A_1;
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
            { const uint16_t sp_call = r->sp; JSR(c, 0x0CF5, 0xC1058B); GUARD_JSR(c, sp_call, 0x0CF5); } /* reject_ineligible_or_nonmonster_actor */
            r->sp += 4;
            uint16_t dp_ret3 = r->dp;
            bool x_ret7 = r->xf;
            uint16_t x_ret8 = r->x;
            bool carry_ret5 = r->c;
            if (carry_ret5) {
                if (x_ret7) {
                    uint8_t value13 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 1));
                    BUS8_SET(c, (uint16_t)(dp_ret3 + 1), (uint8_t)(value13 - 1));
                    if ((uint8_t)(value13 - 1) != 0) {
                        a1 = (uint8_t)((uint8_t)x_ret8 + 0x0200);
                        a_hi1 = (uint8_t)x_ret8 + 0x0200 >> 8;
                        x1 = (uint8_t)((uint8_t)x_ret8 + 0x0200);
                        y1 = (uint8_t)y1;
                        carry1 = (uint8_t)x_ret8 + 0x0200 > 0xFFFF;
                        zero1 = (uint8_t)(value13 - 1) == 0;
                        negative1 = (uint8_t)(value13 - 1) & 0x80;
                        overflow1 = (((uint8_t)x_ret8 ^ (uint8_t)x_ret8 + 0x0200) & ((uint8_t)x_ret8 + 0x0200 ^ 0x0200) & 0x8000) != 0;
                        direct_page = dp_ret3;
                        continue;
                    }
                    a_0d1a = 0xFF;
                    a_hi_0d1a = (uint8_t)x_ret8 + 0x0200 >> 8;
                    y_0d1a = (uint8_t)y1;
                    direct_page_0d1a = dp_ret3;
                    goto shared_0D1A;
                } else {
                    uint8_t value14 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 1));
                    BUS8_SET(c, (uint16_t)(dp_ret3 + 1), (uint8_t)(value14 - 1));
                    if ((uint8_t)(value14 - 1) != 0) {
                        a1 = (uint8_t)(x_ret8 + 0x0200);
                        a_hi1 = (uint16_t)(x_ret8 + 0x0200) >> 8;
                        x1 = (uint16_t)(x_ret8 + 0x0200);
                        y1 = (uint8_t)y1;
                        carry1 = x_ret8 + 0x0200 > 0xFFFF;
                        zero1 = (uint8_t)(value14 - 1) == 0;
                        negative1 = (uint8_t)(value14 - 1) & 0x80;
                        overflow1 = ((x_ret8 ^ (uint16_t)(x_ret8 + 0x0200)) & ((uint16_t)(x_ret8 + 0x0200) ^ 0x0200) & 0x8000) != 0;
                        direct_page = dp_ret3;
                        width_pass = 0;
                        continue;
                    }
                    a_0d1a2 = 0xFF;
                    a_hi_0d1a2 = (uint16_t)(x_ret8 + 0x0200) >> 8;
                    y_0d1a2 = (uint8_t)y1;
                    direct_page_0d1a2 = dp_ret3;
                    goto shared_0D1A_1;
                }
            }
            r->mf = 1;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR(c, 0x0CFA, 0xC10358); GUARD_JSR(c, sp_call, 0x0CFA); } /* classify_actor_squared_distance */
            r->sp += 4;
            if (r->mf != 1) { c->fail = 3; return; }
            bool x_ret9 = r->xf;
            uint16_t a_all6 = r->a;
            bool overflow_ret6 = r->v;
            if ((uint8_t)((uint8_t)a_all6 - 0x20) & 0x80) {
                if (!overflow_ret6) {
                    if (x_ret9) {
                        a_0d17 = (uint8_t)a_all6;
                        a_hi_0d17 = a_all6 >> 8;
                        x_0d17 = (uint8_t)x_ret8;
                        y_0d17 = (uint8_t)y1;
                        direct_page_0d17 = dp_ret3;
                        goto shared_0D17;
                    } else {
                        a_0d172 = (uint8_t)a_all6;
                        a_hi_0d172 = a_all6 >> 8;
                        x_0d172 = x_ret8;
                        y_0d172 = (uint8_t)y1;
                        direct_page_0d172 = dp_ret3;
                        goto shared_0D17_1;
                    }
                }
                if (x_ret9) {
                    uint8_t value15 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 1));
                    BUS8_SET(c, (uint16_t)(dp_ret3 + 1), (uint8_t)(value15 - 1));
                    if ((uint8_t)(value15 - 1) != 0) {
                        a1 = (uint8_t)((uint8_t)x_ret8 + 0x0200);
                        a_hi1 = (uint8_t)x_ret8 + 0x0200 >> 8;
                        x1 = (uint8_t)((uint8_t)x_ret8 + 0x0200);
                        y1 = (uint8_t)y1;
                        carry1 = (uint8_t)x_ret8 + 0x0200 > 0xFFFF;
                        zero1 = (uint8_t)(value15 - 1) == 0;
                        negative1 = (uint8_t)(value15 - 1) & 0x80;
                        overflow1 = (((uint8_t)x_ret8 ^ (uint8_t)x_ret8 + 0x0200) & ((uint8_t)x_ret8 + 0x0200 ^ 0x0200) & 0x8000) != 0;
                        direct_page = dp_ret3;
                        continue;
                    }
                    a_0d1a = 0xFF;
                    a_hi_0d1a = (uint8_t)x_ret8 + 0x0200 >> 8;
                    y_0d1a = (uint8_t)y1;
                    direct_page_0d1a = dp_ret3;
                    goto shared_0D1A;
                } else {
                    uint8_t value16 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 1));
                    BUS8_SET(c, (uint16_t)(dp_ret3 + 1), (uint8_t)(value16 - 1));
                    if ((uint8_t)(value16 - 1) != 0) {
                        a1 = (uint8_t)(x_ret8 + 0x0200);
                        a_hi1 = (uint16_t)(x_ret8 + 0x0200) >> 8;
                        x1 = (uint16_t)(x_ret8 + 0x0200);
                        y1 = (uint8_t)y1;
                        carry1 = x_ret8 + 0x0200 > 0xFFFF;
                        zero1 = (uint8_t)(value16 - 1) == 0;
                        negative1 = (uint8_t)(value16 - 1) & 0x80;
                        overflow1 = ((x_ret8 ^ (uint16_t)(x_ret8 + 0x0200)) & ((uint16_t)(x_ret8 + 0x0200) ^ 0x0200) & 0x8000) != 0;
                        direct_page = dp_ret3;
                        width_pass = 0;
                        continue;
                    }
                    a_0d1a2 = 0xFF;
                    a_hi_0d1a2 = (uint16_t)(x_ret8 + 0x0200) >> 8;
                    y_0d1a2 = (uint8_t)y1;
                    direct_page_0d1a2 = dp_ret3;
                    goto shared_0D1A_1;
                }
            }
            if (overflow_ret6) {
                if (x_ret9) {
                    a_0d17 = (uint8_t)a_all6;
                    a_hi_0d17 = a_all6 >> 8;
                    x_0d17 = (uint8_t)x_ret8;
                    y_0d17 = (uint8_t)y1;
                    direct_page_0d17 = dp_ret3;
                    goto shared_0D17;
                } else {
                    a_0d172 = (uint8_t)a_all6;
                    a_hi_0d172 = a_all6 >> 8;
                    x_0d172 = x_ret8;
                    y_0d172 = (uint8_t)y1;
                    direct_page_0d172 = dp_ret3;
                    goto shared_0D17_1;
                }
            }
            if (x_ret9) {
                uint8_t value17 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 1));
                BUS8_SET(c, (uint16_t)(dp_ret3 + 1), (uint8_t)(value17 - 1));
                if ((uint8_t)(value17 - 1) != 0) {
                    a1 = (uint8_t)((uint8_t)x_ret8 + 0x0200);
                    a_hi1 = (uint8_t)x_ret8 + 0x0200 >> 8;
                    x1 = (uint8_t)((uint8_t)x_ret8 + 0x0200);
                    y1 = (uint8_t)y1;
                    carry1 = (uint8_t)x_ret8 + 0x0200 > 0xFFFF;
                    zero1 = (uint8_t)(value17 - 1) == 0;
                    negative1 = (uint8_t)(value17 - 1) & 0x80;
                    overflow1 = (((uint8_t)x_ret8 ^ (uint8_t)x_ret8 + 0x0200) & ((uint8_t)x_ret8 + 0x0200 ^ 0x0200) & 0x8000) != 0;
                    direct_page = dp_ret3;
                    continue;
                }
                a_0d1a = 0xFF;
                a_hi_0d1a = (uint8_t)x_ret8 + 0x0200 >> 8;
                y_0d1a = (uint8_t)y1;
                direct_page_0d1a = dp_ret3;
                goto shared_0D1A;
            } else {
                uint8_t value18 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 1));
                BUS8_SET(c, (uint16_t)(dp_ret3 + 1), (uint8_t)(value18 - 1));
                if ((uint8_t)(value18 - 1) != 0) {
                    a1 = (uint8_t)(x_ret8 + 0x0200);
                    a_hi1 = (uint16_t)(x_ret8 + 0x0200) >> 8;
                    x1 = (uint16_t)(x_ret8 + 0x0200);
                    y1 = (uint8_t)y1;
                    carry1 = x_ret8 + 0x0200 > 0xFFFF;
                    zero1 = (uint8_t)(value18 - 1) == 0;
                    negative1 = (uint8_t)(value18 - 1) & 0x80;
                    overflow1 = ((x_ret8 ^ (uint16_t)(x_ret8 + 0x0200)) & ((uint16_t)(x_ret8 + 0x0200) ^ 0x0200) & 0x8000) != 0;
                    direct_page = dp_ret3;
                    width_pass = 0;
                    continue;
                }
                a_0d1a2 = 0xFF;
                a_hi_0d1a2 = (uint16_t)(x_ret8 + 0x0200) >> 8;
                y_0d1a2 = (uint8_t)y1;
                direct_page_0d1a2 = dp_ret3;
                goto shared_0D1A_1;
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
            { const uint16_t sp_call = r->sp; JSR(c, 0x0CF5, 0xC1058B); GUARD_JSR(c, sp_call, 0x0CF5); } /* reject_ineligible_or_nonmonster_actor */
            r->sp += 4;
            uint16_t dp_ret4 = r->dp;
            bool x_ret10 = r->xf;
            uint16_t x_ret11 = r->x;
            bool carry_ret7 = r->c;
            if (carry_ret7) {
                if (x_ret10) {
                    uint8_t value19 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 1));
                    BUS8_SET(c, (uint16_t)(dp_ret4 + 1), (uint8_t)(value19 - 1));
                    if ((uint8_t)(value19 - 1) != 0) {
                        a1 = (uint8_t)((uint8_t)x_ret11 + 0x0200);
                        a_hi1 = (uint8_t)x_ret11 + 0x0200 >> 8;
                        x1 = (uint8_t)((uint8_t)x_ret11 + 0x0200);
                        y1 = (uint8_t)y1;
                        carry1 = (uint8_t)x_ret11 + 0x0200 > 0xFFFF;
                        zero1 = (uint8_t)(value19 - 1) == 0;
                        negative1 = (uint8_t)(value19 - 1) & 0x80;
                        overflow1 = (((uint8_t)x_ret11 ^ (uint8_t)x_ret11 + 0x0200) & ((uint8_t)x_ret11 + 0x0200 ^ 0x0200) & 0x8000) != 0;
                        direct_page = dp_ret4;
                        width_pass = 1;
                        continue;
                    }
                    a_0d1a = 0xFF;
                    a_hi_0d1a = (uint8_t)x_ret11 + 0x0200 >> 8;
                    y_0d1a = (uint8_t)y1;
                    direct_page_0d1a = dp_ret4;
                    goto shared_0D1A;
                } else {
                    uint8_t value20 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 1));
                    BUS8_SET(c, (uint16_t)(dp_ret4 + 1), (uint8_t)(value20 - 1));
                    if ((uint8_t)(value20 - 1) != 0) {
                        a1 = (uint8_t)(x_ret11 + 0x0200);
                        a_hi1 = (uint16_t)(x_ret11 + 0x0200) >> 8;
                        x1 = (uint16_t)(x_ret11 + 0x0200);
                        carry1 = x_ret11 + 0x0200 > 0xFFFF;
                        zero1 = (uint8_t)(value20 - 1) == 0;
                        negative1 = (uint8_t)(value20 - 1) & 0x80;
                        overflow1 = ((x_ret11 ^ (uint16_t)(x_ret11 + 0x0200)) & ((uint16_t)(x_ret11 + 0x0200) ^ 0x0200) & 0x8000) != 0;
                        direct_page = dp_ret4;
                        continue;
                    }
                    a_0d1a2 = 0xFF;
                    a_hi_0d1a2 = (uint16_t)(x_ret11 + 0x0200) >> 8;
                    y_0d1a2 = y1;
                    direct_page_0d1a2 = dp_ret4;
                    goto shared_0D1A_1;
                }
            }
            r->mf = 1;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR(c, 0x0CFA, 0xC10358); GUARD_JSR(c, sp_call, 0x0CFA); } /* classify_actor_squared_distance */
            r->sp += 4;
            if (r->mf != 1) { c->fail = 3; return; }
            bool x_ret12 = r->xf;
            uint16_t a_all8 = r->a;
            bool overflow_ret8 = r->v;
            if ((uint8_t)((uint8_t)a_all8 - 0x20) & 0x80) {
                if (!overflow_ret8) {
                    if (x_ret12) {
                        a_0d17 = (uint8_t)a_all8;
                        a_hi_0d17 = a_all8 >> 8;
                        x_0d17 = (uint8_t)x_ret11;
                        y_0d17 = (uint8_t)y1;
                        direct_page_0d17 = dp_ret4;
                        goto shared_0D17;
                    } else {
                        a_0d172 = (uint8_t)a_all8;
                        a_hi_0d172 = a_all8 >> 8;
                        x_0d172 = x_ret11;
                        y_0d172 = y1;
                        direct_page_0d172 = dp_ret4;
                        goto shared_0D17_1;
                    }
                }
                if (x_ret12) {
                    uint8_t value21 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 1));
                    BUS8_SET(c, (uint16_t)(dp_ret4 + 1), (uint8_t)(value21 - 1));
                    if ((uint8_t)(value21 - 1) != 0) {
                        a1 = (uint8_t)((uint8_t)x_ret11 + 0x0200);
                        a_hi1 = (uint8_t)x_ret11 + 0x0200 >> 8;
                        x1 = (uint8_t)((uint8_t)x_ret11 + 0x0200);
                        y1 = (uint8_t)y1;
                        carry1 = (uint8_t)x_ret11 + 0x0200 > 0xFFFF;
                        zero1 = (uint8_t)(value21 - 1) == 0;
                        negative1 = (uint8_t)(value21 - 1) & 0x80;
                        overflow1 = (((uint8_t)x_ret11 ^ (uint8_t)x_ret11 + 0x0200) & ((uint8_t)x_ret11 + 0x0200 ^ 0x0200) & 0x8000) != 0;
                        direct_page = dp_ret4;
                        width_pass = 1;
                        continue;
                    }
                    a_0d1a = 0xFF;
                    a_hi_0d1a = (uint8_t)x_ret11 + 0x0200 >> 8;
                    y_0d1a = (uint8_t)y1;
                    direct_page_0d1a = dp_ret4;
                    goto shared_0D1A;
                } else {
                    uint8_t value22 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 1));
                    BUS8_SET(c, (uint16_t)(dp_ret4 + 1), (uint8_t)(value22 - 1));
                    if ((uint8_t)(value22 - 1) != 0) {
                        a1 = (uint8_t)(x_ret11 + 0x0200);
                        a_hi1 = (uint16_t)(x_ret11 + 0x0200) >> 8;
                        x1 = (uint16_t)(x_ret11 + 0x0200);
                        carry1 = x_ret11 + 0x0200 > 0xFFFF;
                        zero1 = (uint8_t)(value22 - 1) == 0;
                        negative1 = (uint8_t)(value22 - 1) & 0x80;
                        overflow1 = ((x_ret11 ^ (uint16_t)(x_ret11 + 0x0200)) & ((uint16_t)(x_ret11 + 0x0200) ^ 0x0200) & 0x8000) != 0;
                        direct_page = dp_ret4;
                        continue;
                    }
                    a_0d1a2 = 0xFF;
                    a_hi_0d1a2 = (uint16_t)(x_ret11 + 0x0200) >> 8;
                    y_0d1a2 = y1;
                    direct_page_0d1a2 = dp_ret4;
                    goto shared_0D1A_1;
                }
            }
            if (overflow_ret8) {
                if (x_ret12) {
                    a_0d17 = (uint8_t)a_all8;
                    a_hi_0d17 = a_all8 >> 8;
                    x_0d17 = (uint8_t)x_ret11;
                    y_0d17 = (uint8_t)y1;
                    direct_page_0d17 = dp_ret4;
                    goto shared_0D17;
                } else {
                    a_0d172 = (uint8_t)a_all8;
                    a_hi_0d172 = a_all8 >> 8;
                    x_0d172 = x_ret11;
                    y_0d172 = y1;
                    direct_page_0d172 = dp_ret4;
                    goto shared_0D17_1;
                }
            }
            if (x_ret12) {
                uint8_t value23 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 1));
                BUS8_SET(c, (uint16_t)(dp_ret4 + 1), (uint8_t)(value23 - 1));
                if ((uint8_t)(value23 - 1) != 0) {
                    a1 = (uint8_t)((uint8_t)x_ret11 + 0x0200);
                    a_hi1 = (uint8_t)x_ret11 + 0x0200 >> 8;
                    x1 = (uint8_t)((uint8_t)x_ret11 + 0x0200);
                    y1 = (uint8_t)y1;
                    carry1 = (uint8_t)x_ret11 + 0x0200 > 0xFFFF;
                    zero1 = (uint8_t)(value23 - 1) == 0;
                    negative1 = (uint8_t)(value23 - 1) & 0x80;
                    overflow1 = (((uint8_t)x_ret11 ^ (uint8_t)x_ret11 + 0x0200) & ((uint8_t)x_ret11 + 0x0200 ^ 0x0200) & 0x8000) != 0;
                    direct_page = dp_ret4;
                    width_pass = 1;
                    continue;
                }
                a_0d1a = 0xFF;
                a_hi_0d1a = (uint8_t)x_ret11 + 0x0200 >> 8;
                y_0d1a = (uint8_t)y1;
                direct_page_0d1a = dp_ret4;
                goto shared_0D1A;
            } else {
                uint8_t value24 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 1));
                BUS8_SET(c, (uint16_t)(dp_ret4 + 1), (uint8_t)(value24 - 1));
                if ((uint8_t)(value24 - 1) != 0) {
                    a1 = (uint8_t)(x_ret11 + 0x0200);
                    a_hi1 = (uint16_t)(x_ret11 + 0x0200) >> 8;
                    x1 = (uint16_t)(x_ret11 + 0x0200);
                    carry1 = x_ret11 + 0x0200 > 0xFFFF;
                    zero1 = (uint8_t)(value24 - 1) == 0;
                    negative1 = (uint8_t)(value24 - 1) & 0x80;
                    overflow1 = ((x_ret11 ^ (uint16_t)(x_ret11 + 0x0200)) & ((uint16_t)(x_ret11 + 0x0200) ^ 0x0200) & 0x8000) != 0;
                    direct_page = dp_ret4;
                    continue;
                }
                a_0d1a2 = 0xFF;
                a_hi_0d1a2 = (uint16_t)(x_ret11 + 0x0200) >> 8;
                y_0d1a2 = y1;
                direct_page_0d1a2 = dp_ret4;
                goto shared_0D1A_1;
            }
        }
    }
    shared_0D1A:;
    RAM8(0x0000 + sp0 - 3) = (uint8_t)a_0d1a;
    uint8_t value25 = RAM8(0x0000 + sp0 - 3);
    uint8_t value26 = RAM8(0x0000 + sp0 - 2);
    uint8_t value27 = RAM8(0x0000 + sp0 - 1);
    uint8_t value28 = RAM8(0x0000 + sp0);
    r->a = (a_hi_0d1a << 8) | value25;
    r->y = y_0d1a;
    r->v = value26 & 0x40;
    r->mf = value26 & 0x20;
    r->xf = value26 & 0x10;
    r->db = 0x7E;
    r->dp = (value28 << 8) | value27;
    r->i = value26 & 0x04;
    r->d = value26 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
    shared_0D1A_1:;
    RAM8(0x0000 + sp0 - 3) = (uint8_t)a_0d1a2;
    uint8_t value29 = RAM8(0x0000 + sp0 - 3);
    uint8_t value30 = RAM8(0x0000 + sp0 - 2);
    uint8_t value31 = RAM8(0x0000 + sp0 - 1);
    uint8_t value32 = RAM8(0x0000 + sp0);
    r->a = (a_hi_0d1a2 << 8) | value29;
    r->y = y_0d1a2;
    r->v = value30 & 0x40;
    r->mf = value30 & 0x20;
    r->xf = value30 & 0x10;
    r->db = 0x7E;
    r->dp = (value32 << 8) | value31;
    r->i = value30 & 0x04;
    r->d = value30 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
    shared_0D17:;
    r->a = (a_hi_0d17 << 8) | a_0d17;
    r->x = x_0d17;
    r->y = y_0d17;
    r->mf = 1;
    r->xf = 1;
    r->db = 0x7E;
    r->dp = direct_page_0d17;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x0D19, 0xC105CF); GUARD_JSR(c, sp_call, 0x0D19); } /* actor_slot_from_address_high_byte */
    r->sp += 4;
    uint16_t a_all9 = r->a;
    a_0d1a = (uint8_t)a_all9;
    a_hi_0d1a = a_all9 >> 8;
    y_0d1a = y_0d17;
    direct_page_0d1a = direct_page_0d17;
    goto shared_0D1A;
    shared_0D17_1:;
    r->a = (a_hi_0d172 << 8) | a_0d172;
    r->x = x_0d172;
    r->y = y_0d172;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = direct_page_0d172;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x0D19, 0xC105CF); GUARD_JSR(c, sp_call, 0x0D19); } /* actor_slot_from_address_high_byte */
    r->sp += 4;
    uint16_t a_all10 = r->a;
    a_0d1a2 = (uint8_t)a_all10;
    a_hi_0d1a2 = a_all10 >> 8;
    y_0d1a2 = y_0d172;
    direct_page_0d1a2 = direct_page_0d172;
    goto shared_0D1A_1;
}
SOM_REGISTER(0xC10CE3, SOM_RTS, "gen", find_first_eligible_ally_below_class_32, 0, L_A | L_Y | L_V, 4, 1, 0, 61, 34)
