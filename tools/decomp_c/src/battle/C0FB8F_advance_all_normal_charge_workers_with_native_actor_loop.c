#include "som_c.h"

static void advance_actor_charge_status_and_offscreen_retention_worker(SomCtx *c);
static void advance_actor_charge_status_and_offscreen_retention_worker_v3(SomCtx *c);

/* C0FB8F advance_all_normal_charge_workers_with_native_actor_loop   [class B, 159 bytes, 70 instructions]
 * Source: src/rom/advance_all_normal_charge_workers_with_native_actor_loop.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void advance_all_normal_charge_workers_with_native_actor_loop(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t sp_in = r->sp;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool carry = r->c;
    uint8_t a_hi_fb9d = 0;
    uint16_t x_fb9d = 0;
    uint16_t y_fb9d = 0;
    bool carry_fb9d = 0;
    bool overflow_fb9d = 0;
    uint8_t a_hi_fb9d2 = 0;
    uint16_t x_fb9d2 = 0;
    uint16_t y_fb9d2 = 0;
    bool carry_fb9d2 = 0;
    bool overflow_fb9d2 = 0;
    uint16_t direct_page_fb9d = 0;
    uint8_t data_bank_fb9d = 0;
    uint8_t a_hi_fbaf = 0;
    uint16_t x_fbaf = 0;
    uint16_t y_fbaf = 0;
    bool carry_fbaf = 0;
    bool overflow_fbaf = 0;
    uint16_t direct_page_fbaf = 0;
    uint8_t data_bank_fbaf = 0;
    uint8_t value = RAM8(0x00ED);
    if (value & 0x80) {
        a_hi_fb9d = a_hi;
        x_fb9d = 0x0A00;
        y_fb9d = y;
        carry_fb9d = carry;
        overflow_fb9d = value & 0x40;
        goto shared_FB9D;
    }
    a_hi_fb9d = a_hi;
    x_fb9d = 0x1600;
    y_fb9d = y;
    carry_fb9d = carry;
    overflow_fb9d = value & 0x40;
    shared_FB9D:;
    RAM8(0x0000 + sp0) = x_fb9d >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)x_fb9d;
    r->a = (a_hi_fb9d << 8) | a;
    r->x = x_fb9d;
    r->y = y_fb9d;
    r->c = carry_fb9d;
    r->v = overflow_fb9d;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xFBA0, advance_actor_charge_status_and_offscreen_retention_worker, sp_in, 2); GUARD_JSR(c, sp_call, 0xFBA0); }
    r->sp += 2;
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    uint16_t y_ret = r->y;
    uint8_t value2 = RAM8(0x0000 + sp0 - 1);
    uint8_t value3 = RAM8(0x0000 + sp0);
    if ((uint16_t)(((value3 << 8) | value2) - 0x0200) >= 0x0600) {
        a_hi_fb9d2 = (uint16_t)(((value3 << 8) | value2) - 0x0200) >> 8;
        x_fb9d2 = (uint16_t)(((value3 << 8) | value2) - 0x0200);
        y_fb9d2 = y_ret;
        carry_fb9d2 = (uint16_t)(((value3 << 8) | value2) - 0x0200) >= 0x0600;
        overflow_fb9d2 = ((((value3 << 8) | value2) ^ 0x0200) & (((value3 << 8) | value2) ^ (uint16_t)(((value3 << 8) | value2) - 0x0200)) & 0x8000) != 0;
        direct_page_fb9d = dp_ret;
        data_bank_fb9d = db_ret;
        goto shared_FB9D_1;
    }
    a_hi_fbaf = (uint16_t)(((value3 << 8) | value2) - 0x0200) >> 8;
    x_fbaf = (uint16_t)(((value3 << 8) | value2) - 0x0200);
    y_fbaf = y_ret;
    carry_fbaf = (uint16_t)(((value3 << 8) | value2) - 0x0200) >= 0x0600;
    overflow_fbaf = ((((value3 << 8) | value2) ^ 0x0200) & (((value3 << 8) | value2) ^ (uint16_t)(((value3 << 8) | value2) - 0x0200)) & 0x8000) != 0;
    direct_page_fbaf = dp_ret;
    data_bank_fbaf = db_ret;
    goto shared_FBAF;
    shared_FB9D_1:;
    RAM8(0x0000 + sp0) = x_fb9d2 >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)x_fb9d2;
    r->a = (a_hi_fb9d2 << 8) | a;
    r->x = x_fb9d2;
    r->y = y_fb9d2;
    r->c = carry_fb9d2;
    r->v = overflow_fb9d2;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_fb9d;
    r->dp = direct_page_fb9d;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xFBA0, advance_actor_charge_status_and_offscreen_retention_worker_v3, sp_in, 2); GUARD_JSR(c, sp_call, 0xFBA0); }
    r->sp += 2;
    uint16_t dp_ret2 = r->dp;
    uint8_t db_ret2 = r->db;
    uint16_t y_ret2 = r->y;
    uint8_t value4 = RAM8(0x0000 + sp0 - 1);
    uint8_t value5 = RAM8(0x0000 + sp0);
    if ((uint16_t)(((value5 << 8) | value4) - 0x0200) >= 0x0600) {
        a_hi_fb9d2 = (uint16_t)(((value5 << 8) | value4) - 0x0200) >> 8;
        x_fb9d2 = (uint16_t)(((value5 << 8) | value4) - 0x0200);
        y_fb9d2 = y_ret2;
        carry_fb9d2 = (uint16_t)(((value5 << 8) | value4) - 0x0200) >= 0x0600;
        overflow_fb9d2 = ((((value5 << 8) | value4) ^ 0x0200) & (((value5 << 8) | value4) ^ (uint16_t)(((value5 << 8) | value4) - 0x0200)) & 0x8000) != 0;
        direct_page_fb9d = dp_ret2;
        data_bank_fb9d = db_ret2;
        goto shared_FB9D_1;
    }
    a_hi_fbaf = (uint16_t)(((value5 << 8) | value4) - 0x0200) >> 8;
    x_fbaf = (uint16_t)(((value5 << 8) | value4) - 0x0200);
    y_fbaf = y_ret2;
    carry_fbaf = (uint16_t)(((value5 << 8) | value4) - 0x0200) >= 0x0600;
    overflow_fbaf = ((((value5 << 8) | value4) ^ 0x0200) & (((value5 << 8) | value4) ^ (uint16_t)(((value5 << 8) | value4) - 0x0200)) & 0x8000) != 0;
    direct_page_fbaf = dp_ret2;
    data_bank_fbaf = db_ret2;
    goto shared_FBAF;
    shared_FBAF:;
    r->a = (a_hi_fbaf << 8) | a;
    r->x = x_fbaf;
    r->y = y_fbaf;
    r->c = carry_fbaf;
    r->v = overflow_fbaf;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_fbaf;
    r->dp = direct_page_fbaf;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0FB8F, SOM_RTS, "gen", advance_all_normal_charge_workers_with_native_actor_loop, 0, L_B | L_X | L_Y | L_C | L_V, 10, 1, 0, 159, 70)

/* C0FBB0 advance_actor_charge_status_and_offscreen_retention_worker   [class A, 127 bytes, 54 instructions]
 * Source: src/rom/advance_all_normal_charge_workers_with_native_actor_loop.s
 * Subroutine of advance_all_normal_charge_workers_with_native_actor_loop, translated in place.
 * Entry: M=any X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void advance_actor_charge_status_and_offscreen_retention_worker(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    uint8_t value = RAM8(0xE000 + x);
    if (value & 0x80) {
        SET_A8(r, value);
        r->z = value == 0;
        r->n = value & 0x80;
        r->mf = 1;
        RETURN_RTS(c);
    }
    if (value == 0) {
        SET_A8(r, value);
        r->z = value == 0;
        r->n = value & 0x80;
        r->mf = 1;
        RETURN_RTS(c);
    }
    if (!(RAM8(0x00ED) & 0x80)) {
        uint8_t value3 = RAM8(0x00F1);
        if (value3 & 0x40) {
            SET_A8(r, value);
            r->z = (value & value3) == 0;
            r->n = value3 & 0x80;
            r->v = value3 & 0x40;
            r->mf = 1;
            RETURN_RTS(c);
        }
        uint8_t value4 = RAM8(0x005C);
        if (value4 & 0x80) {
            SET_A8(r, value);
            r->z = (value & value4) == 0;
            r->n = value4 & 0x80;
            r->v = value4 & 0x40;
            r->mf = 1;
            RETURN_RTS(c);
        }
        r->a = (a >> 8 << 8) | value;
        r->z = (value & value4) == 0;
        r->n = value4 & 0x80;
        r->v = value4 & 0x40;
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0xFBFB, 0xC0FC2E); GUARD_JSR(c, sp_call, 0xFBFB); } /* retain_or_remove_offscreen_actor_by_native_worker_gates */
        uint8_t value5 = RAM8(0xE00A + x);
        if (value5 == 0) {
            uint8_t value6 = RAM8(0xE064 + x);
            uint8_t a2;
            bool zero2;
            bool negative2;
            if (value6 & 0x80) {
                a2 = value6;
                zero2 = value6 == 0;
                negative2 = value6 & 0x80;
            } else {
                uint8_t value7 = RAM8(0xE062 + x);
                uint8_t a1;
                bool zero1;
                bool negative1;
                if (value7 == 0) {
                    a1 = value7;
                    zero1 = value7 == 0;
                    negative1 = value7 & 0x80;
                } else {
                    RAM8(0xE062 + x) = (uint8_t)(value7 - 1);
                    a1 = (uint8_t)(value7 - 1);
                    zero1 = (uint8_t)(value7 - 1) == 0;
                    negative1 = (uint8_t)(value7 - 1) & 0x80;
                }
                a2 = a1;
                zero2 = zero1;
                negative2 = negative1;
            }
            SET_A8(r, a2);
            r->z = zero2;
            r->n = negative2;
            r->mf = 1;
            r->xf = 0;
            RETURN_RTS(c);
        }
        RAM8(0xE00A + x) = (uint8_t)(value5 - 1);
        if ((uint8_t)(value5 - 1) == 0) {
            RAM8(0xE011 + x) = (uint8_t)(value5 - 1);
            RAM8(0xE042 + x) = (uint8_t)(value5 - 1);
            RAM8(0xE006 + x) = (uint8_t)(value5 - 1);
            RAM8(0xE007 + x) = (uint8_t)(value5 - 1);
            RAM8(0xE008 + x) = (uint8_t)(value5 - 1);
            RAM8(0xE064 + x) = (uint8_t)(value5 - 1);
            RAM8(0xE062 + x) = (uint8_t)(value5 - 1);
        }
        SET_A8(r, (uint8_t)(value5 - 1));
        r->z = (uint8_t)(value5 - 1) == 0;
        r->n = (uint8_t)(value5 - 1) & 0x80;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint8_t value8 = RAM8(0x005C);
    bool x_flag3;
    uint8_t a_hi3;
    uint16_t x2;
    uint16_t y3;
    bool carry3;
    bool overflow3;
    uint8_t data_bank2;
    if (value8 & 0x80) {
        x_flag3 = 0;
        a_hi3 = a >> 8;
        x2 = x;
        y3 = y;
        carry3 = carry;
        overflow3 = value8 & 0x40;
        data_bank2 = 0x7E;
    } else {
        uint8_t value9 = RAM8(0xE061 + x);
        bool m_flag;
        bool x_flag;
        uint8_t a_hi1;
        uint16_t x1;
        uint16_t y1;
        bool carry1;
        bool overflow1;
        uint8_t data_bank;
        if (value9 == 0) {
            m_flag = 1;
            x_flag = 0;
            a_hi1 = a >> 8;
            x1 = x;
            y1 = y;
            carry1 = carry;
            overflow1 = value8 & 0x40;
            data_bank = 0x7E;
        } else {
            r->a = (a >> 8 << 8) | value9;
            r->z = value9 == 0;
            r->n = value9 & 0x80;
            r->v = value8 & 0x40;
            r->mf = 1;
            { const uint16_t sp_call = r->sp; JSL(c, 0xFBC9, 0x02C221); GUARD_JSL(c, sp_call, 0xFBC9); } /* update_all_three_actor_charge_effect_records */
            uint8_t db_ret = r->db;
            bool m_ret2 = r->mf;
            bool x_ret = r->xf;
            uint16_t a_all2 = r->a;
            uint16_t x_ret2 = r->x;
            uint16_t y_ret = r->y;
            bool carry_ret2 = r->c;
            bool overflow_ret2 = r->v;
            m_flag = m_ret2;
            x_flag = x_ret;
            a_hi1 = a_all2 >> 8;
            x1 = x_ret2;
            y1 = y_ret;
            carry1 = carry_ret2;
            overflow1 = overflow_ret2;
            data_bank = db_ret;
        }
        uint8_t value10 = BUS8_RDP(c, (data_bank << 0x10) + 0xE1ED + x1);
        if (value10 != 0) {
            BUS8_SET(c, (data_bank << 0x10) + 0xE1ED + x1, (uint8_t)(value10 - 1));
        }
        uint8_t value11 = BUS8_RDP(c, (data_bank << 0x10) + 0xE100 + x1);
        bool x_flag2;
        uint8_t a_hi2;
        uint16_t y2;
        bool carry2;
        bool overflow2;
        if (!(value11 & 0x80)) {
            x_flag2 = x_flag;
            a_hi2 = a_hi1;
            y2 = y1;
            carry2 = carry1;
            overflow2 = overflow1;
        } else {
            r->a = (a_hi1 << 8) | value11;
            r->x = x1;
            r->y = y1;
            r->c = carry1;
            r->z = value11 == 0;
            r->n = value11 & 0x80;
            r->v = overflow1;
            r->mf = 1;
            r->xf = x_flag;
            r->db = data_bank;
            { const uint16_t sp_call = r->sp; JSR(c, 0xFBDC, 0xC0ED08); GUARD_JSR(c, sp_call, 0xFBDC); } /* advance_actor_primary_status_palette */
            bool x_ret3 = r->xf;
            uint16_t a_all3 = r->a;
            uint16_t y_ret2 = r->y;
            bool carry_ret3 = r->c;
            bool overflow_ret3 = r->v;
            x_flag2 = x_ret3;
            a_hi2 = a_all3 >> 8;
            y2 = y_ret2;
            carry2 = carry_ret3;
            overflow2 = overflow_ret3;
        }
        x_flag3 = x_flag2;
        a_hi3 = a_hi2;
        x2 = x1;
        y3 = y2;
        carry3 = carry2;
        overflow3 = overflow2;
        data_bank2 = data_bank;
    }
    uint8_t value12 = BUS8_RDP(c, (data_bank2 << 0x10) + 0xE104 + x2);
    bool m_flag2;
    bool x_flag4;
    uint8_t a_hi4;
    uint16_t y4;
    bool carry4;
    bool overflow4;
    uint8_t data_bank3;
    uint16_t direct_page;
    if (!(value12 & 0x80)) {
        m_flag2 = 1;
        x_flag4 = x_flag3;
        a_hi4 = a_hi3;
        y4 = y3;
        carry4 = carry3;
        overflow4 = overflow3;
        data_bank3 = data_bank2;
        direct_page = 0;
    } else {
        r->a = (a_hi3 << 8) | value12;
        r->x = x2;
        r->y = y3;
        r->c = carry3;
        r->z = value12 == 0;
        r->n = value12 & 0x80;
        r->v = overflow3;
        r->mf = 1;
        r->xf = x_flag3;
        r->db = data_bank2;
        { const uint16_t sp_call = r->sp; JSR(c, 0xFBE4, 0xC0EDD7); GUARD_JSR(c, sp_call, 0xFBE4); } /* advance_actor_secondary_status_palette */
        uint16_t dp_ret = r->dp;
        uint8_t db_ret2 = r->db;
        bool m_ret3 = r->mf;
        bool x_ret4 = r->xf;
        uint16_t a_all4 = r->a;
        uint16_t y_ret3 = r->y;
        bool carry_ret4 = r->c;
        bool overflow_ret4 = r->v;
        m_flag2 = m_ret3;
        x_flag4 = x_ret4;
        a_hi4 = a_all4 >> 8;
        y4 = y_ret3;
        carry4 = carry_ret4;
        overflow4 = overflow_ret4;
        data_bank3 = db_ret2;
        direct_page = dp_ret;
    }
    if (m_flag2) {
        uint8_t value13 = BUS8_RDP(c, (data_bank3 << 0x10) + 0xE060 + x2);
        if (value13 == 0) {
            uint8_t value14 = BUS8_RDP(c, (uint16_t)(direct_page + 0xF1));
            if (value14 & 0x40) {
                r->a = (a_hi4 << 8) | value13;
                r->x = x2;
                r->y = y4;
                r->c = carry4;
                r->z = (value13 & value14) == 0;
                r->n = value14 & 0x80;
                r->v = value14 & 0x40;
                r->mf = 1;
                r->xf = x_flag4;
                r->db = data_bank3;
                r->dp = direct_page;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
            uint8_t value15 = BUS8_RDP(c, (uint16_t)(direct_page + 0x5C));
            if (value15 & 0x80) {
                r->a = (a_hi4 << 8) | value13;
                r->x = x2;
                r->y = y4;
                r->c = carry4;
                r->z = (value13 & value15) == 0;
                r->n = value15 & 0x80;
                r->v = value15 & 0x40;
                r->mf = 1;
                r->xf = x_flag4;
                r->db = data_bank3;
                r->dp = direct_page;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
            r->a = (a_hi4 << 8) | value13;
            r->x = x2;
            r->y = y4;
            r->c = carry4;
            r->z = (value13 & value15) == 0;
            r->n = value15 & 0x80;
            r->v = value15 & 0x40;
            r->mf = 1;
            r->xf = x_flag4;
            r->db = data_bank3;
            r->dp = direct_page;
            { const uint16_t sp_call = r->sp; JSR(c, 0xFBFB, 0xC0FC2E); GUARD_JSR(c, sp_call, 0xFBFB); } /* retain_or_remove_offscreen_actor_by_native_worker_gates */
            uint8_t value16 = BUS8_RDP(c, (data_bank3 << 0x10) + 0xE00A + x2);
            if (value16 == 0) {
                uint8_t value17 = BUS8_RDP(c, (data_bank3 << 0x10) + 0xE064 + x2);
                uint8_t a4;
                bool zero4;
                bool negative4;
                if (value17 & 0x80) {
                    a4 = value17;
                    zero4 = value17 == 0;
                    negative4 = value17 & 0x80;
                } else {
                    uint8_t value18 = BUS8_RDP(c, (data_bank3 << 0x10) + 0xE062 + x2);
                    uint8_t a3;
                    bool zero3;
                    bool negative3;
                    if (value18 == 0) {
                        a3 = value18;
                        zero3 = value18 == 0;
                        negative3 = value18 & 0x80;
                    } else {
                        BUS8_SET(c, (data_bank3 << 0x10) + 0xE062 + x2, (uint8_t)(value18 - 1));
                        a3 = (uint8_t)(value18 - 1);
                        zero3 = (uint8_t)(value18 - 1) == 0;
                        negative3 = (uint8_t)(value18 - 1) & 0x80;
                    }
                    a4 = a3;
                    zero4 = zero3;
                    negative4 = negative3;
                }
                SET_A8(r, a4);
                r->z = zero4;
                r->n = negative4;
                r->mf = 1;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
            BUS8_SET(c, (data_bank3 << 0x10) + 0xE00A + x2, (uint8_t)(value16 - 1));
            if ((uint8_t)(value16 - 1) == 0) {
                BUS8_SET(c, (data_bank3 << 0x10) + 0xE011 + x2, (uint8_t)(value16 - 1));
                BUS8_SET(c, (data_bank3 << 0x10) + 0xE042 + x2, (uint8_t)(value16 - 1));
                BUS8_SET(c, (data_bank3 << 0x10) + 0xE006 + x2, (uint8_t)(value16 - 1));
                BUS8_SET(c, (data_bank3 << 0x10) + 0xE007 + x2, (uint8_t)(value16 - 1));
                BUS8_SET(c, (data_bank3 << 0x10) + 0xE008 + x2, (uint8_t)(value16 - 1));
                BUS8_SET(c, (data_bank3 << 0x10) + 0xE064 + x2, (uint8_t)(value16 - 1));
                BUS8_SET(c, (data_bank3 << 0x10) + 0xE062 + x2, (uint8_t)(value16 - 1));
            }
            SET_A8(r, (uint8_t)(value16 - 1));
            r->z = (uint8_t)(value16 - 1) == 0;
            r->n = (uint8_t)(value16 - 1) & 0x80;
            r->mf = 1;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
        r->a = (a_hi4 << 8) | value13;
        r->x = x2;
        r->y = y4;
        r->c = carry4;
        r->z = value13 == 0;
        r->n = value13 & 0x80;
        r->v = overflow4;
        r->mf = 1;
        r->xf = x_flag4;
        r->db = data_bank3;
        r->dp = direct_page;
        { const uint16_t sp_call = r->sp; JSL(c, 0xFBED, 0x01833A); GUARD_JSL(c, sp_call, 0xFBED); } /* dispatch_actor_counter_or_spell_visual_effect_frame */
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    } else {
        uint16_t value19 = BUS16_RDP(c, (data_bank3 << 0x10) + 0xE060 + x2);
        if (value19 == 0) {
            uint8_t value20 = BUS8_RDP(c, (uint16_t)(direct_page + 0xF1));
            if (value20 & 0x40) {
                r->a = value19;
                r->x = x2;
                r->y = y4;
                r->c = carry4;
                r->z = ((uint8_t)value19 & value20) == 0;
                r->n = value20 & 0x80;
                r->v = value20 & 0x40;
                r->mf = 1;
                r->xf = x_flag4;
                r->db = data_bank3;
                r->dp = direct_page;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
            uint8_t value21 = BUS8_RDP(c, (uint16_t)(direct_page + 0x5C));
            if (value21 & 0x80) {
                r->a = value19;
                r->x = x2;
                r->y = y4;
                r->c = carry4;
                r->z = ((uint8_t)value19 & value21) == 0;
                r->n = value21 & 0x80;
                r->v = value21 & 0x40;
                r->mf = 1;
                r->xf = x_flag4;
                r->db = data_bank3;
                r->dp = direct_page;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
            r->a = value19;
            r->x = x2;
            r->y = y4;
            r->c = carry4;
            r->z = ((uint8_t)value19 & value21) == 0;
            r->n = value21 & 0x80;
            r->v = value21 & 0x40;
            r->mf = 1;
            r->xf = x_flag4;
            r->db = data_bank3;
            r->dp = direct_page;
            { const uint16_t sp_call = r->sp; JSR(c, 0xFBFB, 0xC0FC2E); GUARD_JSR(c, sp_call, 0xFBFB); } /* retain_or_remove_offscreen_actor_by_native_worker_gates */
            uint8_t value22 = BUS8_RDP(c, (data_bank3 << 0x10) + 0xE00A + x2);
            if (value22 == 0) {
                uint8_t value23 = BUS8_RDP(c, (data_bank3 << 0x10) + 0xE064 + x2);
                uint8_t a6;
                bool zero6;
                bool negative6;
                if (value23 & 0x80) {
                    a6 = value23;
                    zero6 = value23 == 0;
                    negative6 = value23 & 0x80;
                } else {
                    uint8_t value24 = BUS8_RDP(c, (data_bank3 << 0x10) + 0xE062 + x2);
                    uint8_t a5;
                    bool zero5;
                    bool negative5;
                    if (value24 == 0) {
                        a5 = value24;
                        zero5 = value24 == 0;
                        negative5 = value24 & 0x80;
                    } else {
                        BUS8_SET(c, (data_bank3 << 0x10) + 0xE062 + x2, (uint8_t)(value24 - 1));
                        a5 = (uint8_t)(value24 - 1);
                        zero5 = (uint8_t)(value24 - 1) == 0;
                        negative5 = (uint8_t)(value24 - 1) & 0x80;
                    }
                    a6 = a5;
                    zero6 = zero5;
                    negative6 = negative5;
                }
                SET_A8(r, a6);
                r->z = zero6;
                r->n = negative6;
                r->mf = 1;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
            BUS8_SET(c, (data_bank3 << 0x10) + 0xE00A + x2, (uint8_t)(value22 - 1));
            if ((uint8_t)(value22 - 1) == 0) {
                BUS8_SET(c, (data_bank3 << 0x10) + 0xE011 + x2, (uint8_t)(value22 - 1));
                BUS8_SET(c, (data_bank3 << 0x10) + 0xE042 + x2, (uint8_t)(value22 - 1));
                BUS8_SET(c, (data_bank3 << 0x10) + 0xE006 + x2, (uint8_t)(value22 - 1));
                BUS8_SET(c, (data_bank3 << 0x10) + 0xE007 + x2, (uint8_t)(value22 - 1));
                BUS8_SET(c, (data_bank3 << 0x10) + 0xE008 + x2, (uint8_t)(value22 - 1));
                BUS8_SET(c, (data_bank3 << 0x10) + 0xE064 + x2, (uint8_t)(value22 - 1));
                BUS8_SET(c, (data_bank3 << 0x10) + 0xE062 + x2, (uint8_t)(value22 - 1));
            }
            SET_A8(r, (uint8_t)(value22 - 1));
            r->z = (uint8_t)(value22 - 1) == 0;
            r->n = (uint8_t)(value22 - 1) & 0x80;
            r->mf = 1;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
        r->a = value19;
        r->x = x2;
        r->y = y4;
        r->c = carry4;
        r->z = value19 == 0;
        r->n = value19 & 0x8000;
        r->v = overflow4;
        r->mf = 0;
        r->xf = x_flag4;
        r->db = data_bank3;
        r->dp = direct_page;
        { const uint16_t sp_call = r->sp; JSL(c, 0xFBED, 0x01833A); GUARD_JSL(c, sp_call, 0xFBED); } /* dispatch_actor_counter_or_spell_visual_effect_frame */
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
}

/* C0FBB0 advance_actor_charge_status_and_offscreen_retention_worker_v3   [class A, 127 bytes, 54 instructions]
 * Source: src/rom/advance_all_normal_charge_workers_with_native_actor_loop.s
 * Subroutine of advance_all_normal_charge_workers_with_native_actor_loop, translated in place.
 * Entry: M=any X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void advance_actor_charge_status_and_offscreen_retention_worker_v3(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, -1, 0)) return;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const uint8_t db = r->db;
    uint8_t value = BUS8_RDP(c, (db << 0x10) + 0xE000 + x);
    if (value & 0x80) {
        SET_A8(r, value);
        r->z = value == 0;
        r->n = value & 0x80;
        r->mf = 1;
        RETURN_RTS(c);
    }
    if (value == 0) {
        SET_A8(r, value);
        r->z = value == 0;
        r->n = value & 0x80;
        r->mf = 1;
        RETURN_RTS(c);
    }
    uint8_t value2 = BUS8_RDP(c, (uint16_t)(dp + 0xED));
    if (!(value2 & 0x80)) {
        uint8_t value3 = BUS8_RDP(c, (uint16_t)(dp + 0xF1));
        if (value3 & 0x40) {
            SET_A8(r, value);
            r->z = (value & value3) == 0;
            r->n = value3 & 0x80;
            r->v = value3 & 0x40;
            r->mf = 1;
            RETURN_RTS(c);
        }
        uint8_t value4 = BUS8_RDP(c, (uint16_t)(dp + 0x5C));
        if (value4 & 0x80) {
            SET_A8(r, value);
            r->z = (value & value4) == 0;
            r->n = value4 & 0x80;
            r->v = value4 & 0x40;
            r->mf = 1;
            RETURN_RTS(c);
        }
        r->a = (a >> 8 << 8) | value;
        r->z = (value & value4) == 0;
        r->n = value4 & 0x80;
        r->v = value4 & 0x40;
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0xFBFB, 0xC0FC2E); GUARD_JSR(c, sp_call, 0xFBFB); } /* retain_or_remove_offscreen_actor_by_native_worker_gates */
        uint8_t value5 = BUS8_RDP(c, (db << 0x10) + 0xE00A + x);
        if (value5 == 0) {
            uint8_t value6 = BUS8_RDP(c, (db << 0x10) + 0xE064 + x);
            uint8_t a2;
            bool zero2;
            bool negative2;
            if (value6 & 0x80) {
                a2 = value6;
                zero2 = value6 == 0;
                negative2 = value6 & 0x80;
            } else {
                uint8_t value7 = BUS8_RDP(c, (db << 0x10) + 0xE062 + x);
                uint8_t a1;
                bool zero1;
                bool negative1;
                if (value7 == 0) {
                    a1 = value7;
                    zero1 = value7 == 0;
                    negative1 = value7 & 0x80;
                } else {
                    BUS8_SET(c, (db << 0x10) + 0xE062 + x, (uint8_t)(value7 - 1));
                    a1 = (uint8_t)(value7 - 1);
                    zero1 = (uint8_t)(value7 - 1) == 0;
                    negative1 = (uint8_t)(value7 - 1) & 0x80;
                }
                a2 = a1;
                zero2 = zero1;
                negative2 = negative1;
            }
            SET_A8(r, a2);
            r->z = zero2;
            r->n = negative2;
            r->mf = 1;
            r->xf = 0;
            RETURN_RTS(c);
        }
        BUS8_SET(c, (db << 0x10) + 0xE00A + x, (uint8_t)(value5 - 1));
        if ((uint8_t)(value5 - 1) == 0) {
            BUS8_SET(c, (db << 0x10) + 0xE011 + x, (uint8_t)(value5 - 1));
            BUS8_SET(c, (db << 0x10) + 0xE042 + x, (uint8_t)(value5 - 1));
            BUS8_SET(c, (db << 0x10) + 0xE006 + x, (uint8_t)(value5 - 1));
            BUS8_SET(c, (db << 0x10) + 0xE007 + x, (uint8_t)(value5 - 1));
            BUS8_SET(c, (db << 0x10) + 0xE008 + x, (uint8_t)(value5 - 1));
            BUS8_SET(c, (db << 0x10) + 0xE064 + x, (uint8_t)(value5 - 1));
            BUS8_SET(c, (db << 0x10) + 0xE062 + x, (uint8_t)(value5 - 1));
        }
        SET_A8(r, (uint8_t)(value5 - 1));
        r->z = (uint8_t)(value5 - 1) == 0;
        r->n = (uint8_t)(value5 - 1) & 0x80;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint8_t value8 = BUS8_RDP(c, (uint16_t)(dp + 0x5C));
    bool x_flag3;
    uint8_t a_hi3;
    uint16_t x2;
    uint16_t y3;
    bool carry3;
    bool overflow3;
    uint8_t data_bank2;
    if (value8 & 0x80) {
        x_flag3 = 0;
        a_hi3 = a >> 8;
        x2 = x;
        y3 = y;
        carry3 = carry;
        overflow3 = value8 & 0x40;
        data_bank2 = db;
    } else {
        uint8_t value9 = BUS8_RDP(c, (db << 0x10) + 0xE061 + x);
        bool m_flag;
        bool x_flag;
        uint8_t a_hi1;
        uint16_t x1;
        uint16_t y1;
        bool carry1;
        bool overflow1;
        uint8_t data_bank;
        if (value9 == 0) {
            m_flag = 1;
            x_flag = 0;
            a_hi1 = a >> 8;
            x1 = x;
            y1 = y;
            carry1 = carry;
            overflow1 = value8 & 0x40;
            data_bank = db;
        } else {
            r->a = (a >> 8 << 8) | value9;
            r->z = value9 == 0;
            r->n = value9 & 0x80;
            r->v = value8 & 0x40;
            r->mf = 1;
            { const uint16_t sp_call = r->sp; JSL(c, 0xFBC9, 0x02C221); GUARD_JSL(c, sp_call, 0xFBC9); } /* update_all_three_actor_charge_effect_records */
            uint8_t db_ret = r->db;
            bool m_ret2 = r->mf;
            bool x_ret = r->xf;
            uint16_t a_all2 = r->a;
            uint16_t x_ret2 = r->x;
            uint16_t y_ret = r->y;
            bool carry_ret2 = r->c;
            bool overflow_ret2 = r->v;
            m_flag = m_ret2;
            x_flag = x_ret;
            a_hi1 = a_all2 >> 8;
            x1 = x_ret2;
            y1 = y_ret;
            carry1 = carry_ret2;
            overflow1 = overflow_ret2;
            data_bank = db_ret;
        }
        uint8_t value10 = BUS8_RDP(c, (data_bank << 0x10) + 0xE1ED + x1);
        if (value10 != 0) {
            BUS8_SET(c, (data_bank << 0x10) + 0xE1ED + x1, (uint8_t)(value10 - 1));
        }
        uint8_t value11 = BUS8_RDP(c, (data_bank << 0x10) + 0xE100 + x1);
        bool x_flag2;
        uint8_t a_hi2;
        uint16_t y2;
        bool carry2;
        bool overflow2;
        if (!(value11 & 0x80)) {
            x_flag2 = x_flag;
            a_hi2 = a_hi1;
            y2 = y1;
            carry2 = carry1;
            overflow2 = overflow1;
        } else {
            r->a = (a_hi1 << 8) | value11;
            r->x = x1;
            r->y = y1;
            r->c = carry1;
            r->z = value11 == 0;
            r->n = value11 & 0x80;
            r->v = overflow1;
            r->mf = 1;
            r->xf = x_flag;
            r->db = data_bank;
            { const uint16_t sp_call = r->sp; JSR(c, 0xFBDC, 0xC0ED08); GUARD_JSR(c, sp_call, 0xFBDC); } /* advance_actor_primary_status_palette */
            bool x_ret3 = r->xf;
            uint16_t a_all3 = r->a;
            uint16_t y_ret2 = r->y;
            bool carry_ret3 = r->c;
            bool overflow_ret3 = r->v;
            x_flag2 = x_ret3;
            a_hi2 = a_all3 >> 8;
            y2 = y_ret2;
            carry2 = carry_ret3;
            overflow2 = overflow_ret3;
        }
        x_flag3 = x_flag2;
        a_hi3 = a_hi2;
        x2 = x1;
        y3 = y2;
        carry3 = carry2;
        overflow3 = overflow2;
        data_bank2 = data_bank;
    }
    uint8_t value12 = BUS8_RDP(c, (data_bank2 << 0x10) + 0xE104 + x2);
    bool m_flag2;
    bool x_flag4;
    uint8_t a_hi4;
    uint16_t y4;
    bool carry4;
    bool overflow4;
    uint8_t data_bank3;
    uint16_t direct_page;
    if (!(value12 & 0x80)) {
        m_flag2 = 1;
        x_flag4 = x_flag3;
        a_hi4 = a_hi3;
        y4 = y3;
        carry4 = carry3;
        overflow4 = overflow3;
        data_bank3 = data_bank2;
        direct_page = dp;
    } else {
        r->a = (a_hi3 << 8) | value12;
        r->x = x2;
        r->y = y3;
        r->c = carry3;
        r->z = value12 == 0;
        r->n = value12 & 0x80;
        r->v = overflow3;
        r->mf = 1;
        r->xf = x_flag3;
        r->db = data_bank2;
        { const uint16_t sp_call = r->sp; JSR(c, 0xFBE4, 0xC0EDD7); GUARD_JSR(c, sp_call, 0xFBE4); } /* advance_actor_secondary_status_palette */
        uint16_t dp_ret = r->dp;
        uint8_t db_ret2 = r->db;
        bool m_ret3 = r->mf;
        bool x_ret4 = r->xf;
        uint16_t a_all4 = r->a;
        uint16_t y_ret3 = r->y;
        bool carry_ret4 = r->c;
        bool overflow_ret4 = r->v;
        m_flag2 = m_ret3;
        x_flag4 = x_ret4;
        a_hi4 = a_all4 >> 8;
        y4 = y_ret3;
        carry4 = carry_ret4;
        overflow4 = overflow_ret4;
        data_bank3 = db_ret2;
        direct_page = dp_ret;
    }
    if (m_flag2) {
        uint8_t value13 = BUS8_RDP(c, (data_bank3 << 0x10) + 0xE060 + x2);
        if (value13 == 0) {
            uint8_t value14 = BUS8_RDP(c, (uint16_t)(direct_page + 0xF1));
            if (value14 & 0x40) {
                r->a = (a_hi4 << 8) | value13;
                r->x = x2;
                r->y = y4;
                r->c = carry4;
                r->z = (value13 & value14) == 0;
                r->n = value14 & 0x80;
                r->v = value14 & 0x40;
                r->mf = 1;
                r->xf = x_flag4;
                r->db = data_bank3;
                r->dp = direct_page;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
            uint8_t value15 = BUS8_RDP(c, (uint16_t)(direct_page + 0x5C));
            if (value15 & 0x80) {
                r->a = (a_hi4 << 8) | value13;
                r->x = x2;
                r->y = y4;
                r->c = carry4;
                r->z = (value13 & value15) == 0;
                r->n = value15 & 0x80;
                r->v = value15 & 0x40;
                r->mf = 1;
                r->xf = x_flag4;
                r->db = data_bank3;
                r->dp = direct_page;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
            r->a = (a_hi4 << 8) | value13;
            r->x = x2;
            r->y = y4;
            r->c = carry4;
            r->z = (value13 & value15) == 0;
            r->n = value15 & 0x80;
            r->v = value15 & 0x40;
            r->mf = 1;
            r->xf = x_flag4;
            r->db = data_bank3;
            r->dp = direct_page;
            { const uint16_t sp_call = r->sp; JSR(c, 0xFBFB, 0xC0FC2E); GUARD_JSR(c, sp_call, 0xFBFB); } /* retain_or_remove_offscreen_actor_by_native_worker_gates */
            uint8_t value16 = BUS8_RDP(c, (data_bank3 << 0x10) + 0xE00A + x2);
            if (value16 == 0) {
                uint8_t value17 = BUS8_RDP(c, (data_bank3 << 0x10) + 0xE064 + x2);
                uint8_t a4;
                bool zero4;
                bool negative4;
                if (value17 & 0x80) {
                    a4 = value17;
                    zero4 = value17 == 0;
                    negative4 = value17 & 0x80;
                } else {
                    uint8_t value18 = BUS8_RDP(c, (data_bank3 << 0x10) + 0xE062 + x2);
                    uint8_t a3;
                    bool zero3;
                    bool negative3;
                    if (value18 == 0) {
                        a3 = value18;
                        zero3 = value18 == 0;
                        negative3 = value18 & 0x80;
                    } else {
                        BUS8_SET(c, (data_bank3 << 0x10) + 0xE062 + x2, (uint8_t)(value18 - 1));
                        a3 = (uint8_t)(value18 - 1);
                        zero3 = (uint8_t)(value18 - 1) == 0;
                        negative3 = (uint8_t)(value18 - 1) & 0x80;
                    }
                    a4 = a3;
                    zero4 = zero3;
                    negative4 = negative3;
                }
                SET_A8(r, a4);
                r->z = zero4;
                r->n = negative4;
                r->mf = 1;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
            BUS8_SET(c, (data_bank3 << 0x10) + 0xE00A + x2, (uint8_t)(value16 - 1));
            if ((uint8_t)(value16 - 1) == 0) {
                BUS8_SET(c, (data_bank3 << 0x10) + 0xE011 + x2, (uint8_t)(value16 - 1));
                BUS8_SET(c, (data_bank3 << 0x10) + 0xE042 + x2, (uint8_t)(value16 - 1));
                BUS8_SET(c, (data_bank3 << 0x10) + 0xE006 + x2, (uint8_t)(value16 - 1));
                BUS8_SET(c, (data_bank3 << 0x10) + 0xE007 + x2, (uint8_t)(value16 - 1));
                BUS8_SET(c, (data_bank3 << 0x10) + 0xE008 + x2, (uint8_t)(value16 - 1));
                BUS8_SET(c, (data_bank3 << 0x10) + 0xE064 + x2, (uint8_t)(value16 - 1));
                BUS8_SET(c, (data_bank3 << 0x10) + 0xE062 + x2, (uint8_t)(value16 - 1));
            }
            SET_A8(r, (uint8_t)(value16 - 1));
            r->z = (uint8_t)(value16 - 1) == 0;
            r->n = (uint8_t)(value16 - 1) & 0x80;
            r->mf = 1;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
        r->a = (a_hi4 << 8) | value13;
        r->x = x2;
        r->y = y4;
        r->c = carry4;
        r->z = value13 == 0;
        r->n = value13 & 0x80;
        r->v = overflow4;
        r->mf = 1;
        r->xf = x_flag4;
        r->db = data_bank3;
        r->dp = direct_page;
        { const uint16_t sp_call = r->sp; JSL(c, 0xFBED, 0x01833A); GUARD_JSL(c, sp_call, 0xFBED); } /* dispatch_actor_counter_or_spell_visual_effect_frame */
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    } else {
        uint16_t value19 = BUS16_RDP(c, (data_bank3 << 0x10) + 0xE060 + x2);
        if (value19 == 0) {
            uint8_t value20 = BUS8_RDP(c, (uint16_t)(direct_page + 0xF1));
            if (value20 & 0x40) {
                r->a = value19;
                r->x = x2;
                r->y = y4;
                r->c = carry4;
                r->z = ((uint8_t)value19 & value20) == 0;
                r->n = value20 & 0x80;
                r->v = value20 & 0x40;
                r->mf = 1;
                r->xf = x_flag4;
                r->db = data_bank3;
                r->dp = direct_page;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
            uint8_t value21 = BUS8_RDP(c, (uint16_t)(direct_page + 0x5C));
            if (value21 & 0x80) {
                r->a = value19;
                r->x = x2;
                r->y = y4;
                r->c = carry4;
                r->z = ((uint8_t)value19 & value21) == 0;
                r->n = value21 & 0x80;
                r->v = value21 & 0x40;
                r->mf = 1;
                r->xf = x_flag4;
                r->db = data_bank3;
                r->dp = direct_page;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
            r->a = value19;
            r->x = x2;
            r->y = y4;
            r->c = carry4;
            r->z = ((uint8_t)value19 & value21) == 0;
            r->n = value21 & 0x80;
            r->v = value21 & 0x40;
            r->mf = 1;
            r->xf = x_flag4;
            r->db = data_bank3;
            r->dp = direct_page;
            { const uint16_t sp_call = r->sp; JSR(c, 0xFBFB, 0xC0FC2E); GUARD_JSR(c, sp_call, 0xFBFB); } /* retain_or_remove_offscreen_actor_by_native_worker_gates */
            uint8_t value22 = BUS8_RDP(c, (data_bank3 << 0x10) + 0xE00A + x2);
            if (value22 == 0) {
                uint8_t value23 = BUS8_RDP(c, (data_bank3 << 0x10) + 0xE064 + x2);
                uint8_t a6;
                bool zero6;
                bool negative6;
                if (value23 & 0x80) {
                    a6 = value23;
                    zero6 = value23 == 0;
                    negative6 = value23 & 0x80;
                } else {
                    uint8_t value24 = BUS8_RDP(c, (data_bank3 << 0x10) + 0xE062 + x2);
                    uint8_t a5;
                    bool zero5;
                    bool negative5;
                    if (value24 == 0) {
                        a5 = value24;
                        zero5 = value24 == 0;
                        negative5 = value24 & 0x80;
                    } else {
                        BUS8_SET(c, (data_bank3 << 0x10) + 0xE062 + x2, (uint8_t)(value24 - 1));
                        a5 = (uint8_t)(value24 - 1);
                        zero5 = (uint8_t)(value24 - 1) == 0;
                        negative5 = (uint8_t)(value24 - 1) & 0x80;
                    }
                    a6 = a5;
                    zero6 = zero5;
                    negative6 = negative5;
                }
                SET_A8(r, a6);
                r->z = zero6;
                r->n = negative6;
                r->mf = 1;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
            BUS8_SET(c, (data_bank3 << 0x10) + 0xE00A + x2, (uint8_t)(value22 - 1));
            if ((uint8_t)(value22 - 1) == 0) {
                BUS8_SET(c, (data_bank3 << 0x10) + 0xE011 + x2, (uint8_t)(value22 - 1));
                BUS8_SET(c, (data_bank3 << 0x10) + 0xE042 + x2, (uint8_t)(value22 - 1));
                BUS8_SET(c, (data_bank3 << 0x10) + 0xE006 + x2, (uint8_t)(value22 - 1));
                BUS8_SET(c, (data_bank3 << 0x10) + 0xE007 + x2, (uint8_t)(value22 - 1));
                BUS8_SET(c, (data_bank3 << 0x10) + 0xE008 + x2, (uint8_t)(value22 - 1));
                BUS8_SET(c, (data_bank3 << 0x10) + 0xE064 + x2, (uint8_t)(value22 - 1));
                BUS8_SET(c, (data_bank3 << 0x10) + 0xE062 + x2, (uint8_t)(value22 - 1));
            }
            SET_A8(r, (uint8_t)(value22 - 1));
            r->z = (uint8_t)(value22 - 1) == 0;
            r->n = (uint8_t)(value22 - 1) & 0x80;
            r->mf = 1;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
        r->a = value19;
        r->x = x2;
        r->y = y4;
        r->c = carry4;
        r->z = value19 == 0;
        r->n = value19 & 0x8000;
        r->v = overflow4;
        r->mf = 0;
        r->xf = x_flag4;
        r->db = data_bank3;
        r->dp = direct_page;
        { const uint16_t sp_call = r->sp; JSL(c, 0xFBED, 0x01833A); GUARD_JSL(c, sp_call, 0xFBED); } /* dispatch_actor_counter_or_spell_visual_effect_frame */
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
}
