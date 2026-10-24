#include "som_c.h"

/* C10EDF find_first_eligible_monster_within_class_4   [class B, 57 bytes, 32 instructions]
 * Source: src/rom/find_first_eligible_monster_within_class_4.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: AYV.
 */
static void find_first_eligible_monster_within_class_4(SomCtx *c)
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
    uint8_t a_0f0f = 0;
    uint8_t a_hi_0f0f = 0;
    uint8_t x_0f0f = 0;
    uint8_t y_0f0f = 0;
    uint16_t direct_page_0f0f = 0;
    uint8_t a_0f0f2 = 0;
    uint8_t a_hi_0f0f2 = 0;
    uint16_t x_0f0f2 = 0;
    uint16_t y_0f0f2 = 0;
    uint16_t direct_page_0f0f2 = 0;
    uint8_t a_0f12 = 0;
    uint8_t a_hi_0f12 = 0;
    uint8_t y_0f12 = 0;
    uint16_t direct_page_0f12 = 0;
    uint8_t a_0f122 = 0;
    uint8_t a_hi_0f122 = 0;
    uint16_t y_0f122 = 0;
    uint16_t direct_page_0f122 = 0;
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7E;
    RAM8(0x0001 + (uint16_t)(sp0 - 4)) = 0x0C;
    uint8_t a1 = 0x0C;
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
            { const uint16_t sp_call = r->sp; JSR(c, 0x0EF1, 0xC10598); GUARD_JSR(c, sp_call, 0x0EF1); } /* test_eligible_actor_id_at_least_83 */
            r->sp += 4;
            uint16_t dp_ret = r->dp;
            bool x_ret = r->xf;
            uint16_t a_all = r->a;
            uint16_t x_ret2 = r->x;
            bool carry_ret = r->c;
            bool x_flag;
            uint8_t a_hi2;
            if (!carry_ret) {
                x_flag = x_ret;
                a_hi2 = a_all >> 8;
            } else {
                r->mf = 1;
                r->sp -= 4;
                { const uint16_t sp_call = r->sp; JSR(c, 0x0EF6, 0xC10358); GUARD_JSR(c, sp_call, 0x0EF6); } /* classify_actor_squared_distance */
                r->sp += 4;
                if (r->mf != 1) { c->fail = 3; return; }
                bool x_ret3 = r->xf;
                uint16_t a_all2 = r->a;
                if ((uint8_t)a_all2 == 4) {
                    if (x_ret3) {
                        a_0f0f = (uint8_t)a_all2;
                        a_hi_0f0f = a_all2 >> 8;
                        x_0f0f = (uint8_t)x_ret2;
                        y_0f0f = (uint8_t)y1;
                        direct_page_0f0f = dp_ret;
                        goto shared_0F0F;
                    } else {
                        a_0f0f2 = (uint8_t)a_all2;
                        a_hi_0f0f2 = a_all2 >> 8;
                        x_0f0f2 = x_ret2;
                        y_0f0f2 = y1;
                        direct_page_0f0f2 = dp_ret;
                        goto shared_0F0F_1;
                    }
                }
                if ((uint8_t)a_all2 < 4) {
                    if (x_ret3) {
                        a_0f0f = (uint8_t)a_all2;
                        a_hi_0f0f = a_all2 >> 8;
                        x_0f0f = (uint8_t)x_ret2;
                        y_0f0f = (uint8_t)y1;
                        direct_page_0f0f = dp_ret;
                        goto shared_0F0F;
                    } else {
                        a_0f0f2 = (uint8_t)a_all2;
                        a_hi_0f0f2 = a_all2 >> 8;
                        x_0f0f2 = x_ret2;
                        y_0f0f2 = y1;
                        direct_page_0f0f2 = dp_ret;
                        goto shared_0F0F_1;
                    }
                }
                x_flag = x_ret3;
                a_hi2 = a_all2 >> 8;
            }
            if (x_flag) {
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
                a_0f12 = 0xFF;
                a_hi_0f12 = (uint8_t)x_ret2 + 0x0200 >> 8;
                y_0f12 = (uint8_t)y1;
                direct_page_0f12 = dp_ret;
                goto shared_0F12;
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
                a_0f122 = 0xFF;
                a_hi_0f122 = (uint16_t)(x_ret2 + 0x0200) >> 8;
                y_0f122 = y1;
                direct_page_0f122 = dp_ret;
                goto shared_0F12_1;
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
            { const uint16_t sp_call = r->sp; JSR(c, 0x0EF1, 0xC10598); GUARD_JSR(c, sp_call, 0x0EF1); } /* test_eligible_actor_id_at_least_83 */
            r->sp += 4;
            uint16_t dp_ret2 = r->dp;
            bool x_ret4 = r->xf;
            uint16_t a_all3 = r->a;
            uint16_t x_ret5 = r->x;
            bool carry_ret3 = r->c;
            bool x_flag2;
            uint8_t a_hi3;
            if (!carry_ret3) {
                x_flag2 = x_ret4;
                a_hi3 = a_all3 >> 8;
            } else {
                r->mf = 1;
                r->sp -= 4;
                { const uint16_t sp_call = r->sp; JSR(c, 0x0EF6, 0xC10358); GUARD_JSR(c, sp_call, 0x0EF6); } /* classify_actor_squared_distance */
                r->sp += 4;
                if (r->mf != 1) { c->fail = 3; return; }
                bool x_ret6 = r->xf;
                uint16_t a_all4 = r->a;
                if ((uint8_t)a_all4 == 4) {
                    if (x_ret6) {
                        a_0f0f = (uint8_t)a_all4;
                        a_hi_0f0f = a_all4 >> 8;
                        x_0f0f = (uint8_t)x_ret5;
                        y_0f0f = (uint8_t)y1;
                        direct_page_0f0f = dp_ret2;
                        goto shared_0F0F;
                    } else {
                        a_0f0f2 = (uint8_t)a_all4;
                        a_hi_0f0f2 = a_all4 >> 8;
                        x_0f0f2 = x_ret5;
                        y_0f0f2 = (uint8_t)y1;
                        direct_page_0f0f2 = dp_ret2;
                        goto shared_0F0F_1;
                    }
                }
                if ((uint8_t)a_all4 < 4) {
                    if (x_ret6) {
                        a_0f0f = (uint8_t)a_all4;
                        a_hi_0f0f = a_all4 >> 8;
                        x_0f0f = (uint8_t)x_ret5;
                        y_0f0f = (uint8_t)y1;
                        direct_page_0f0f = dp_ret2;
                        goto shared_0F0F;
                    } else {
                        a_0f0f2 = (uint8_t)a_all4;
                        a_hi_0f0f2 = a_all4 >> 8;
                        x_0f0f2 = x_ret5;
                        y_0f0f2 = (uint8_t)y1;
                        direct_page_0f0f2 = dp_ret2;
                        goto shared_0F0F_1;
                    }
                }
                x_flag2 = x_ret6;
                a_hi3 = a_all4 >> 8;
            }
            if (x_flag2) {
                uint8_t value3 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 1));
                BUS8_SET(c, (uint16_t)(dp_ret2 + 1), (uint8_t)(value3 - 1));
                if ((uint8_t)(value3 - 1) != 0) {
                    a1 = (uint8_t)((uint8_t)x_ret5 + 0x0200);
                    a_hi1 = (uint8_t)x_ret5 + 0x0200 >> 8;
                    x1 = (uint8_t)((uint8_t)x_ret5 + 0x0200);
                    y1 = (uint8_t)y1;
                    carry1 = (uint8_t)x_ret5 + 0x0200 > 0xFFFF;
                    zero1 = (uint8_t)(value3 - 1) == 0;
                    negative1 = (uint8_t)(value3 - 1) & 0x80;
                    overflow1 = (((uint8_t)x_ret5 ^ (uint8_t)x_ret5 + 0x0200) & ((uint8_t)x_ret5 + 0x0200 ^ 0x0200) & 0x8000) != 0;
                    direct_page = dp_ret2;
                    continue;
                }
                a_0f12 = 0xFF;
                a_hi_0f12 = (uint8_t)x_ret5 + 0x0200 >> 8;
                y_0f12 = (uint8_t)y1;
                direct_page_0f12 = dp_ret2;
                goto shared_0F12;
            } else {
                uint8_t value4 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 1));
                BUS8_SET(c, (uint16_t)(dp_ret2 + 1), (uint8_t)(value4 - 1));
                if ((uint8_t)(value4 - 1) != 0) {
                    a1 = (uint8_t)(x_ret5 + 0x0200);
                    a_hi1 = (uint16_t)(x_ret5 + 0x0200) >> 8;
                    x1 = (uint16_t)(x_ret5 + 0x0200);
                    y1 = (uint8_t)y1;
                    carry1 = x_ret5 + 0x0200 > 0xFFFF;
                    zero1 = (uint8_t)(value4 - 1) == 0;
                    negative1 = (uint8_t)(value4 - 1) & 0x80;
                    overflow1 = ((x_ret5 ^ (uint16_t)(x_ret5 + 0x0200)) & ((uint16_t)(x_ret5 + 0x0200) ^ 0x0200) & 0x8000) != 0;
                    direct_page = dp_ret2;
                    width_pass = 3;
                    continue;
                }
                a_0f122 = 0xFF;
                a_hi_0f122 = (uint16_t)(x_ret5 + 0x0200) >> 8;
                y_0f122 = (uint8_t)y1;
                direct_page_0f122 = dp_ret2;
                goto shared_0F12_1;
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
            { const uint16_t sp_call = r->sp; JSR(c, 0x0EF1, 0xC10598); GUARD_JSR(c, sp_call, 0x0EF1); } /* test_eligible_actor_id_at_least_83 */
            r->sp += 4;
            uint16_t dp_ret3 = r->dp;
            bool x_ret7 = r->xf;
            uint16_t a_all5 = r->a;
            uint16_t x_ret8 = r->x;
            bool carry_ret5 = r->c;
            bool x_flag3;
            uint8_t a_hi4;
            if (!carry_ret5) {
                x_flag3 = x_ret7;
                a_hi4 = a_all5 >> 8;
            } else {
                r->mf = 1;
                r->sp -= 4;
                { const uint16_t sp_call = r->sp; JSR(c, 0x0EF6, 0xC10358); GUARD_JSR(c, sp_call, 0x0EF6); } /* classify_actor_squared_distance */
                r->sp += 4;
                if (r->mf != 1) { c->fail = 3; return; }
                bool x_ret9 = r->xf;
                uint16_t a_all6 = r->a;
                if ((uint8_t)a_all6 == 4) {
                    if (x_ret9) {
                        a_0f0f = (uint8_t)a_all6;
                        a_hi_0f0f = a_all6 >> 8;
                        x_0f0f = (uint8_t)x_ret8;
                        y_0f0f = (uint8_t)y1;
                        direct_page_0f0f = dp_ret3;
                        goto shared_0F0F;
                    } else {
                        a_0f0f2 = (uint8_t)a_all6;
                        a_hi_0f0f2 = a_all6 >> 8;
                        x_0f0f2 = x_ret8;
                        y_0f0f2 = (uint8_t)y1;
                        direct_page_0f0f2 = dp_ret3;
                        goto shared_0F0F_1;
                    }
                }
                if ((uint8_t)a_all6 < 4) {
                    if (x_ret9) {
                        a_0f0f = (uint8_t)a_all6;
                        a_hi_0f0f = a_all6 >> 8;
                        x_0f0f = (uint8_t)x_ret8;
                        y_0f0f = (uint8_t)y1;
                        direct_page_0f0f = dp_ret3;
                        goto shared_0F0F;
                    } else {
                        a_0f0f2 = (uint8_t)a_all6;
                        a_hi_0f0f2 = a_all6 >> 8;
                        x_0f0f2 = x_ret8;
                        y_0f0f2 = (uint8_t)y1;
                        direct_page_0f0f2 = dp_ret3;
                        goto shared_0F0F_1;
                    }
                }
                x_flag3 = x_ret9;
                a_hi4 = a_all6 >> 8;
            }
            if (x_flag3) {
                uint8_t value5 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 1));
                BUS8_SET(c, (uint16_t)(dp_ret3 + 1), (uint8_t)(value5 - 1));
                if ((uint8_t)(value5 - 1) != 0) {
                    a1 = (uint8_t)((uint8_t)x_ret8 + 0x0200);
                    a_hi1 = (uint8_t)x_ret8 + 0x0200 >> 8;
                    x1 = (uint8_t)((uint8_t)x_ret8 + 0x0200);
                    y1 = (uint8_t)y1;
                    carry1 = (uint8_t)x_ret8 + 0x0200 > 0xFFFF;
                    zero1 = (uint8_t)(value5 - 1) == 0;
                    negative1 = (uint8_t)(value5 - 1) & 0x80;
                    overflow1 = (((uint8_t)x_ret8 ^ (uint8_t)x_ret8 + 0x0200) & ((uint8_t)x_ret8 + 0x0200 ^ 0x0200) & 0x8000) != 0;
                    direct_page = dp_ret3;
                    continue;
                }
                a_0f12 = 0xFF;
                a_hi_0f12 = (uint8_t)x_ret8 + 0x0200 >> 8;
                y_0f12 = (uint8_t)y1;
                direct_page_0f12 = dp_ret3;
                goto shared_0F12;
            } else {
                uint8_t value6 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 1));
                BUS8_SET(c, (uint16_t)(dp_ret3 + 1), (uint8_t)(value6 - 1));
                if ((uint8_t)(value6 - 1) != 0) {
                    a1 = (uint8_t)(x_ret8 + 0x0200);
                    a_hi1 = (uint16_t)(x_ret8 + 0x0200) >> 8;
                    x1 = (uint16_t)(x_ret8 + 0x0200);
                    y1 = (uint8_t)y1;
                    carry1 = x_ret8 + 0x0200 > 0xFFFF;
                    zero1 = (uint8_t)(value6 - 1) == 0;
                    negative1 = (uint8_t)(value6 - 1) & 0x80;
                    overflow1 = ((x_ret8 ^ (uint16_t)(x_ret8 + 0x0200)) & ((uint16_t)(x_ret8 + 0x0200) ^ 0x0200) & 0x8000) != 0;
                    direct_page = dp_ret3;
                    width_pass = 0;
                    continue;
                }
                a_0f122 = 0xFF;
                a_hi_0f122 = (uint16_t)(x_ret8 + 0x0200) >> 8;
                y_0f122 = (uint8_t)y1;
                direct_page_0f122 = dp_ret3;
                goto shared_0F12_1;
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
            { const uint16_t sp_call = r->sp; JSR(c, 0x0EF1, 0xC10598); GUARD_JSR(c, sp_call, 0x0EF1); } /* test_eligible_actor_id_at_least_83 */
            r->sp += 4;
            uint16_t dp_ret4 = r->dp;
            bool x_ret10 = r->xf;
            uint16_t a_all7 = r->a;
            uint16_t x_ret11 = r->x;
            bool carry_ret7 = r->c;
            bool x_flag4;
            uint8_t a_hi5;
            if (!carry_ret7) {
                x_flag4 = x_ret10;
                a_hi5 = a_all7 >> 8;
            } else {
                r->mf = 1;
                r->sp -= 4;
                { const uint16_t sp_call = r->sp; JSR(c, 0x0EF6, 0xC10358); GUARD_JSR(c, sp_call, 0x0EF6); } /* classify_actor_squared_distance */
                r->sp += 4;
                if (r->mf != 1) { c->fail = 3; return; }
                bool x_ret12 = r->xf;
                uint16_t a_all8 = r->a;
                if ((uint8_t)a_all8 == 4) {
                    if (x_ret12) {
                        a_0f0f = (uint8_t)a_all8;
                        a_hi_0f0f = a_all8 >> 8;
                        x_0f0f = (uint8_t)x_ret11;
                        y_0f0f = (uint8_t)y1;
                        direct_page_0f0f = dp_ret4;
                        goto shared_0F0F;
                    } else {
                        a_0f0f2 = (uint8_t)a_all8;
                        a_hi_0f0f2 = a_all8 >> 8;
                        x_0f0f2 = x_ret11;
                        y_0f0f2 = y1;
                        direct_page_0f0f2 = dp_ret4;
                        goto shared_0F0F_1;
                    }
                }
                if ((uint8_t)a_all8 < 4) {
                    if (x_ret12) {
                        a_0f0f = (uint8_t)a_all8;
                        a_hi_0f0f = a_all8 >> 8;
                        x_0f0f = (uint8_t)x_ret11;
                        y_0f0f = (uint8_t)y1;
                        direct_page_0f0f = dp_ret4;
                        goto shared_0F0F;
                    } else {
                        a_0f0f2 = (uint8_t)a_all8;
                        a_hi_0f0f2 = a_all8 >> 8;
                        x_0f0f2 = x_ret11;
                        y_0f0f2 = y1;
                        direct_page_0f0f2 = dp_ret4;
                        goto shared_0F0F_1;
                    }
                }
                x_flag4 = x_ret12;
                a_hi5 = a_all8 >> 8;
            }
            if (x_flag4) {
                uint8_t value7 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 1));
                BUS8_SET(c, (uint16_t)(dp_ret4 + 1), (uint8_t)(value7 - 1));
                if ((uint8_t)(value7 - 1) != 0) {
                    a1 = (uint8_t)((uint8_t)x_ret11 + 0x0200);
                    a_hi1 = (uint8_t)x_ret11 + 0x0200 >> 8;
                    x1 = (uint8_t)((uint8_t)x_ret11 + 0x0200);
                    y1 = (uint8_t)y1;
                    carry1 = (uint8_t)x_ret11 + 0x0200 > 0xFFFF;
                    zero1 = (uint8_t)(value7 - 1) == 0;
                    negative1 = (uint8_t)(value7 - 1) & 0x80;
                    overflow1 = (((uint8_t)x_ret11 ^ (uint8_t)x_ret11 + 0x0200) & ((uint8_t)x_ret11 + 0x0200 ^ 0x0200) & 0x8000) != 0;
                    direct_page = dp_ret4;
                    width_pass = 1;
                    continue;
                }
                a_0f12 = 0xFF;
                a_hi_0f12 = (uint8_t)x_ret11 + 0x0200 >> 8;
                y_0f12 = (uint8_t)y1;
                direct_page_0f12 = dp_ret4;
                goto shared_0F12;
            } else {
                uint8_t value8 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 1));
                BUS8_SET(c, (uint16_t)(dp_ret4 + 1), (uint8_t)(value8 - 1));
                if ((uint8_t)(value8 - 1) != 0) {
                    a1 = (uint8_t)(x_ret11 + 0x0200);
                    a_hi1 = (uint16_t)(x_ret11 + 0x0200) >> 8;
                    x1 = (uint16_t)(x_ret11 + 0x0200);
                    carry1 = x_ret11 + 0x0200 > 0xFFFF;
                    zero1 = (uint8_t)(value8 - 1) == 0;
                    negative1 = (uint8_t)(value8 - 1) & 0x80;
                    overflow1 = ((x_ret11 ^ (uint16_t)(x_ret11 + 0x0200)) & ((uint16_t)(x_ret11 + 0x0200) ^ 0x0200) & 0x8000) != 0;
                    direct_page = dp_ret4;
                    continue;
                }
                a_0f122 = 0xFF;
                a_hi_0f122 = (uint16_t)(x_ret11 + 0x0200) >> 8;
                y_0f122 = y1;
                direct_page_0f122 = dp_ret4;
                goto shared_0F12_1;
            }
        }
    }
    shared_0F0F:;
    r->a = (a_hi_0f0f << 8) | a_0f0f;
    r->x = x_0f0f;
    r->y = y_0f0f;
    r->mf = 1;
    r->xf = 1;
    r->db = 0x7E;
    r->dp = direct_page_0f0f;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x0F11, 0xC105CF); GUARD_JSR(c, sp_call, 0x0F11); } /* actor_slot_from_address_high_byte */
    r->sp += 4;
    uint16_t a_all9 = r->a;
    a_0f12 = (uint8_t)a_all9;
    a_hi_0f12 = a_all9 >> 8;
    y_0f12 = y_0f0f;
    direct_page_0f12 = direct_page_0f0f;
    goto shared_0F12;
    shared_0F0F_1:;
    r->a = (a_hi_0f0f2 << 8) | a_0f0f2;
    r->x = x_0f0f2;
    r->y = y_0f0f2;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = direct_page_0f0f2;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x0F11, 0xC105CF); GUARD_JSR(c, sp_call, 0x0F11); } /* actor_slot_from_address_high_byte */
    r->sp += 4;
    uint16_t a_all10 = r->a;
    a_0f122 = (uint8_t)a_all10;
    a_hi_0f122 = a_all10 >> 8;
    y_0f122 = y_0f0f2;
    direct_page_0f122 = direct_page_0f0f2;
    goto shared_0F12_1;
    shared_0F12:;
    RAM8(0x0000 + sp0 - 3) = (uint8_t)a_0f12;
    uint8_t value9 = RAM8(0x0000 + sp0 - 3);
    uint8_t value10 = RAM8(0x0000 + sp0 - 2);
    uint8_t value11 = RAM8(0x0000 + sp0 - 1);
    uint8_t value12 = RAM8(0x0000 + sp0);
    r->a = (a_hi_0f12 << 8) | value9;
    r->y = y_0f12;
    r->v = value10 & 0x40;
    r->mf = value10 & 0x20;
    r->xf = value10 & 0x10;
    r->db = 0x7E;
    r->dp = (value12 << 8) | value11;
    r->i = value10 & 0x04;
    r->d = value10 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
    shared_0F12_1:;
    RAM8(0x0000 + sp0 - 3) = (uint8_t)a_0f122;
    uint8_t value13 = RAM8(0x0000 + sp0 - 3);
    uint8_t value14 = RAM8(0x0000 + sp0 - 2);
    uint8_t value15 = RAM8(0x0000 + sp0 - 1);
    uint8_t value16 = RAM8(0x0000 + sp0);
    r->a = (a_hi_0f122 << 8) | value13;
    r->y = y_0f122;
    r->v = value14 & 0x40;
    r->mf = value14 & 0x20;
    r->xf = value14 & 0x10;
    r->db = 0x7E;
    r->dp = (value16 << 8) | value15;
    r->i = value14 & 0x04;
    r->d = value14 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC10EDF, SOM_RTS, "gen", find_first_eligible_monster_within_class_4, 0, L_A | L_Y | L_V, 4, 1, 0, 57, 32)
