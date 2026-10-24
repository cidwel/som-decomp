#include "som_c.h"

/* D0D397 prepare_and_run_complete_native_menu_dialogue_frame   [class C, 89 bytes, 38 instructions]
 * Source: src/rom/prepare_and_run_complete_native_menu_dialogue_frame.s
 * Documented in docs/event-menu-text-tick.md
 * Entry: M=16 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void prepare_and_run_complete_native_menu_dialogue_frame_m16x16(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 0, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    RAM8(0x0000 + sp0) = x >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)x;
    RAM8(0x0000 + sp0 - 2) = y >> 8;
    RAM8(0x0000 + sp0 - 3) = (uint8_t)y;
    RAM8(0x0000 + sp0 - 4) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    uint8_t value = BUS8_RDP(c, (db << 0x10) + 0x1802);
    bool m_flag4;
    bool x_flag4;
    uint8_t a4;
    uint8_t a_hi4;
    uint8_t data_bank4;
    uint16_t direct_page4;
    if ((value & 4) == 0) {
        uint8_t value2 = BUS8_RDP(c, (db << 0x10) + 0x1D04);
        bool m_flag;
        bool x_flag;
        uint8_t a1;
        uint8_t a_hi1;
        uint8_t data_bank;
        uint16_t direct_page;
        if ((value2 & 1) == 0) {
            m_flag = 1;
            x_flag = 0;
            a1 = 1;
            a_hi1 = a >> 8;
            data_bank = db;
            direct_page = dp;
        } else {
            BUS8_SET(c, (db << 0x10) + 0x1D13, 0);
            r->a = (a >> 8 << 8) | 1;
            r->z = (value2 & 1) == 0;
            r->n = value2 & 0x80;
            r->v = value2 & 0x40;
            r->mf = 1;
            r->sp -= 5;
            { const uint16_t sp_call = r->sp; JSL(c, 0xD3EB, 0xC00092); GUARD_JSL(c, sp_call, 0xD3EB); } /* run_native_dialogue_public_jump */
            r->sp += 5;
            uint16_t dp_ret = r->dp;
            uint8_t db_ret = r->db;
            bool m_ret = r->mf;
            bool x_ret = r->xf;
            uint16_t a_all = r->a;
            m_flag = m_ret;
            x_flag = x_ret;
            a1 = (uint8_t)a_all;
            a_hi1 = a_all >> 8;
            data_bank = db_ret;
            direct_page = dp_ret;
        }
        m_flag4 = m_flag;
        x_flag4 = x_flag;
        a4 = a1;
        a_hi4 = a_hi1;
        data_bank4 = data_bank;
        direct_page4 = direct_page;
    } else {
        uint8_t value3 = BUS8_RDP(c, (db << 0x10) + 0x1802);
        BUS8_SET(c, (db << 0x10) + 0x1802, value3 & 0xFB);
        uint8_t value4 = BUS8_RDP(c, (db << 0x10) + 0x1803);
        bool m_flag3;
        bool x_flag3;
        uint8_t a3;
        uint8_t a_hi3;
        uint8_t data_bank3;
        uint16_t direct_page3;
        if ((value4 & 0x10) != 0) {
            uint8_t value5 = BUS8_RDP(c, (db << 0x10) + 0x1D04);
            bool m_flag2;
            bool x_flag2;
            uint8_t a2;
            uint8_t a_hi2;
            uint8_t data_bank2;
            uint16_t direct_page2;
            if ((value5 & 1) == 0) {
                m_flag2 = 1;
                x_flag2 = 0;
                a2 = 1;
                a_hi2 = a >> 8;
                data_bank2 = db;
                direct_page2 = dp;
            } else {
                BUS8_SET(c, (db << 0x10) + 0x1D13, 0);
                r->a = (a >> 8 << 8) | 1;
                r->z = (value5 & 1) == 0;
                r->n = value5 & 0x80;
                r->v = value5 & 0x40;
                r->mf = 1;
                r->sp -= 5;
                { const uint16_t sp_call = r->sp; JSL(c, 0xD3EB, 0xC00092); GUARD_JSL(c, sp_call, 0xD3EB); } /* run_native_dialogue_public_jump */
                r->sp += 5;
                uint16_t dp_ret2 = r->dp;
                uint8_t db_ret2 = r->db;
                bool m_ret2 = r->mf;
                bool x_ret3 = r->xf;
                uint16_t a_all2 = r->a;
                m_flag2 = m_ret2;
                x_flag2 = x_ret3;
                a2 = (uint8_t)a_all2;
                a_hi2 = a_all2 >> 8;
                data_bank2 = db_ret2;
                direct_page2 = dp_ret2;
            }
            m_flag3 = m_flag2;
            x_flag3 = x_flag2;
            a3 = a2;
            a_hi3 = a_hi2;
            data_bank3 = data_bank2;
            direct_page3 = direct_page2;
        } else {
            BUS16_SET(c, (db << 0x10) + 0x19D0, 0x527F);
            BUS16_SET(c, (db << 0x10) + 0x19D2, 0x55);
            BUS16_SET(c, (db << 0x10) + 0x19D4, 0);
            r->a = 0x55;
            r->sp -= 5;
            { const uint16_t sp_call = r->sp; JSL(c, 0xD3C1, 0xC06BE2); GUARD_JSL(c, sp_call, 0xD3C1); } /* calculate_wrapped_native_menu_row_index */
            r->sp += 5;
            uint16_t a_all3 = r->a;
            BUS8_SET(c, (db << 0x10) + 0x19D3, (uint8_t)a_all3);
            r->mf = 1;
            r->xf = 0;
            r->sp -= 5;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD3C9, 0xD0D3F0); GUARD_JSR(c, sp_call, 0xD3C9); } /* select_complete_native_menu_description_script */
            r->sp += 5;
            r->sp -= 5;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD3CC, 0xD0D5F3); GUARD_JSR(c, sp_call, 0xD3CC); } /* dispatch_native_menu_second_line_description */
            r->sp += 5;
            uint8_t db_ret3 = r->db;
            r->a = 0;
            r->x = 0x19D0;
            r->mf = 0;
            r->xf = 0;
            r->sp -= 5;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD3D7, 0xD0D5D7); GUARD_JSR(c, sp_call, 0xD3D7); } /* set_native_menu_dialogue_script_and_close_prior_window */
            r->sp += 5;
            BUS8_SET(c, (db_ret3 << 0x10) + 0x1D13, 0);
            r->mf = 1;
            r->xf = 0;
            r->sp -= 5;
            { const uint16_t sp_call = r->sp; JSL(c, 0xD3EB, 0xC00092); GUARD_JSL(c, sp_call, 0xD3EB); } /* run_native_dialogue_public_jump */
            r->sp += 5;
            uint16_t dp_ret4 = r->dp;
            uint8_t db_ret4 = r->db;
            bool m_ret5 = r->mf;
            bool x_ret10 = r->xf;
            uint16_t a_all7 = r->a;
            m_flag3 = m_ret5;
            x_flag3 = x_ret10;
            a3 = (uint8_t)a_all7;
            a_hi3 = a_all7 >> 8;
            data_bank3 = db_ret4;
            direct_page3 = dp_ret4;
        }
        m_flag4 = m_flag3;
        x_flag4 = x_flag3;
        a4 = a3;
        a_hi4 = a_hi3;
        data_bank4 = data_bank3;
        direct_page4 = direct_page3;
    }
    uint8_t value6 = RAM8(0x0000 + sp0 - 4);
    if (value6 & 0x10) {
        c->fail = 3;
        return;
    } else {
        uint8_t value9 = RAM8(0x0000 + sp0 - 3);
        uint8_t value10 = RAM8(0x0000 + sp0 - 2);
        uint8_t value11 = RAM8(0x0000 + sp0 - 1);
        uint8_t value12 = RAM8(0x0000 + sp0);
        r->a = (a_hi4 << 8) | a4;
        r->x = (value12 << 8) | value11;
        r->y = (value10 << 8) | value9;
        r->c = value6 & 0x01;
        r->z = ((value12 << 8) | value11) == 0;
        r->n = ((value12 << 8) | value11) & 0x8000;
        r->v = value6 & 0x40;
        r->mf = value6 & 0x20;
        r->xf = 0;
        r->db = data_bank4;
        r->dp = direct_page4;
        r->i = value6 & 0x04;
        r->d = value6 & 0x08;
        RETURN_RTL(c);
    }
}

/* D0D397 prepare_and_run_complete_native_menu_dialogue_frame   [class C, 89 bytes, 38 instructions]
 * Source: src/rom/prepare_and_run_complete_native_menu_dialogue_frame.s
 * Documented in docs/event-menu-text-tick.md
 * Entry: M=16 bit X=8 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void prepare_and_run_complete_native_menu_dialogue_frame_m16x8(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 0, 1)) return;
    const uint16_t sp0 = r->sp + 2;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const uint8_t x = r->x;
    const uint8_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    RAM8(0x0000 + sp0 - 2) = x;
    RAM8(0x0000 + sp0 - 3) = y;
    RAM8(0x0000 + sp0 - 4) = ((((negative << 7) | (overflow << 6) | 0x10) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    uint8_t value = BUS8_RDP(c, (db << 0x10) + 0x1802);
    bool m_flag4;
    bool x_flag4;
    uint8_t a4;
    uint8_t a_hi4;
    uint8_t data_bank4;
    uint16_t direct_page4;
    if ((value & 4) == 0) {
        uint8_t value2 = BUS8_RDP(c, (db << 0x10) + 0x1D04);
        bool m_flag;
        bool x_flag;
        uint8_t a1;
        uint8_t a_hi1;
        uint8_t data_bank;
        uint16_t direct_page;
        if ((value2 & 1) == 0) {
            m_flag = 1;
            x_flag = 1;
            a1 = 1;
            a_hi1 = a >> 8;
            data_bank = db;
            direct_page = dp;
        } else {
            BUS8_SET(c, (db << 0x10) + 0x1D13, 0);
            r->a = (a >> 8 << 8) | 1;
            r->z = (value2 & 1) == 0;
            r->n = value2 & 0x80;
            r->v = value2 & 0x40;
            r->mf = 1;
            r->sp -= 3;
            { const uint16_t sp_call = r->sp; JSL(c, 0xD3EB, 0xC00092); GUARD_JSL(c, sp_call, 0xD3EB); } /* run_native_dialogue_public_jump */
            r->sp += 3;
            uint16_t dp_ret = r->dp;
            uint8_t db_ret = r->db;
            bool m_ret = r->mf;
            bool x_ret = r->xf;
            uint16_t a_all = r->a;
            m_flag = m_ret;
            x_flag = x_ret;
            a1 = (uint8_t)a_all;
            a_hi1 = a_all >> 8;
            data_bank = db_ret;
            direct_page = dp_ret;
        }
        m_flag4 = m_flag;
        x_flag4 = x_flag;
        a4 = a1;
        a_hi4 = a_hi1;
        data_bank4 = data_bank;
        direct_page4 = direct_page;
    } else {
        uint8_t value3 = BUS8_RDP(c, (db << 0x10) + 0x1802);
        BUS8_SET(c, (db << 0x10) + 0x1802, value3 & 0xFB);
        uint8_t value4 = BUS8_RDP(c, (db << 0x10) + 0x1803);
        bool m_flag3;
        bool x_flag3;
        uint8_t a3;
        uint8_t a_hi3;
        uint8_t data_bank3;
        uint16_t direct_page3;
        if ((value4 & 0x10) != 0) {
            uint8_t value5 = BUS8_RDP(c, (db << 0x10) + 0x1D04);
            bool m_flag2;
            bool x_flag2;
            uint8_t a2;
            uint8_t a_hi2;
            uint8_t data_bank2;
            uint16_t direct_page2;
            if ((value5 & 1) == 0) {
                m_flag2 = 1;
                x_flag2 = 1;
                a2 = 1;
                a_hi2 = a >> 8;
                data_bank2 = db;
                direct_page2 = dp;
            } else {
                BUS8_SET(c, (db << 0x10) + 0x1D13, 0);
                r->a = (a >> 8 << 8) | 1;
                r->z = (value5 & 1) == 0;
                r->n = value5 & 0x80;
                r->v = value5 & 0x40;
                r->mf = 1;
                r->sp -= 3;
                { const uint16_t sp_call = r->sp; JSL(c, 0xD3EB, 0xC00092); GUARD_JSL(c, sp_call, 0xD3EB); } /* run_native_dialogue_public_jump */
                r->sp += 3;
                uint16_t dp_ret2 = r->dp;
                uint8_t db_ret2 = r->db;
                bool m_ret2 = r->mf;
                bool x_ret3 = r->xf;
                uint16_t a_all2 = r->a;
                m_flag2 = m_ret2;
                x_flag2 = x_ret3;
                a2 = (uint8_t)a_all2;
                a_hi2 = a_all2 >> 8;
                data_bank2 = db_ret2;
                direct_page2 = dp_ret2;
            }
            m_flag3 = m_flag2;
            x_flag3 = x_flag2;
            a3 = a2;
            a_hi3 = a_hi2;
            data_bank3 = data_bank2;
            direct_page3 = direct_page2;
        } else {
            BUS16_SET(c, (db << 0x10) + 0x19D0, 0x527F);
            BUS16_SET(c, (db << 0x10) + 0x19D2, 0x55);
            BUS16_SET(c, (db << 0x10) + 0x19D4, 0);
            r->a = 0x55;
            r->xf = 0;
            r->sp -= 3;
            { const uint16_t sp_call = r->sp; JSL(c, 0xD3C1, 0xC06BE2); GUARD_JSL(c, sp_call, 0xD3C1); } /* calculate_wrapped_native_menu_row_index */
            r->sp += 3;
            uint16_t a_all3 = r->a;
            BUS8_SET(c, (db << 0x10) + 0x19D3, (uint8_t)a_all3);
            r->mf = 1;
            r->xf = 0;
            r->sp -= 3;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD3C9, 0xD0D3F0); GUARD_JSR(c, sp_call, 0xD3C9); } /* select_complete_native_menu_description_script */
            r->sp += 3;
            r->sp -= 3;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD3CC, 0xD0D5F3); GUARD_JSR(c, sp_call, 0xD3CC); } /* dispatch_native_menu_second_line_description */
            r->sp += 3;
            uint8_t db_ret3 = r->db;
            r->a = 0;
            r->x = 0x19D0;
            r->mf = 0;
            r->xf = 0;
            r->sp -= 3;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD3D7, 0xD0D5D7); GUARD_JSR(c, sp_call, 0xD3D7); } /* set_native_menu_dialogue_script_and_close_prior_window */
            r->sp += 3;
            BUS8_SET(c, (db_ret3 << 0x10) + 0x1D13, 0);
            r->mf = 1;
            r->xf = 0;
            r->sp -= 3;
            { const uint16_t sp_call = r->sp; JSL(c, 0xD3EB, 0xC00092); GUARD_JSL(c, sp_call, 0xD3EB); } /* run_native_dialogue_public_jump */
            r->sp += 3;
            uint16_t dp_ret4 = r->dp;
            uint8_t db_ret4 = r->db;
            bool m_ret5 = r->mf;
            bool x_ret10 = r->xf;
            uint16_t a_all7 = r->a;
            m_flag3 = m_ret5;
            x_flag3 = x_ret10;
            a3 = (uint8_t)a_all7;
            a_hi3 = a_all7 >> 8;
            data_bank3 = db_ret4;
            direct_page3 = dp_ret4;
        }
        m_flag4 = m_flag3;
        x_flag4 = x_flag3;
        a4 = a3;
        a_hi4 = a_hi3;
        data_bank4 = data_bank3;
        direct_page4 = direct_page3;
    }
    uint8_t value6 = RAM8(0x0000 + sp0 - 4);
    if (value6 & 0x10) {
        uint8_t value7 = RAM8(0x0000 + sp0 - 3);
        uint8_t value8 = RAM8(0x0000 + sp0 - 2);
        r->a = (a_hi4 << 8) | a4;
        r->x = value8;
        r->y = value7;
        r->c = value6 & 0x01;
        r->z = value8 == 0;
        r->n = value8 & 0x80;
        r->v = value6 & 0x40;
        r->mf = value6 & 0x20;
        r->xf = 1;
        r->db = data_bank4;
        r->dp = direct_page4;
        r->i = value6 & 0x04;
        r->d = value6 & 0x08;
        RETURN_RTL(c);
    } else {
        uint8_t value9 = RAM8(0x0000 + sp0 - 3);
        uint8_t value10 = RAM8(0x0000 + sp0 - 2);
        uint8_t value11 = RAM8(0x0000 + sp0 - 1);
        uint8_t value12 = RAM8(0x0000 + sp0);
        r->a = (a_hi4 << 8) | a4;
        r->x = (value12 << 8) | value11;
        r->y = (value10 << 8) | value9;
        r->c = value6 & 0x01;
        r->z = ((value12 << 8) | value11) == 0;
        r->n = ((value12 << 8) | value11) & 0x8000;
        r->v = value6 & 0x40;
        r->mf = value6 & 0x20;
        r->xf = 0;
        r->db = data_bank4;
        r->dp = direct_page4;
        r->i = value6 & 0x04;
        r->d = value6 & 0x08;
        r->sp += 2;
        RETURN_RTL(c);
    }
}

/* D0D397 prepare_and_run_complete_native_menu_dialogue_frame   [class C, 89 bytes, 38 instructions]
 * Source: src/rom/prepare_and_run_complete_native_menu_dialogue_frame.s
 * Documented in docs/event-menu-text-tick.md
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void prepare_and_run_complete_native_menu_dialogue_frame_m8x16(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    RAM8(0x0000 + sp0) = x >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)x;
    RAM8(0x0000 + sp0 - 2) = y >> 8;
    RAM8(0x0000 + sp0 - 3) = (uint8_t)y;
    RAM8(0x0000 + sp0 - 4) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    uint8_t value = BUS8_RDP(c, (db << 0x10) + 0x1802);
    bool m_flag4;
    bool x_flag4;
    uint8_t a4;
    uint8_t a_hi4;
    uint8_t data_bank4;
    uint16_t direct_page4;
    if ((value & 4) == 0) {
        uint8_t value2 = BUS8_RDP(c, (db << 0x10) + 0x1D04);
        bool m_flag;
        bool x_flag;
        uint8_t a1;
        uint8_t a_hi1;
        uint8_t data_bank;
        uint16_t direct_page;
        if ((value2 & 1) == 0) {
            m_flag = 1;
            x_flag = 0;
            a1 = 1;
            a_hi1 = a_hi;
            data_bank = db;
            direct_page = dp;
        } else {
            BUS8_SET(c, (db << 0x10) + 0x1D13, 0);
            r->a = (a_hi << 8) | 1;
            r->z = (value2 & 1) == 0;
            r->n = value2 & 0x80;
            r->v = value2 & 0x40;
            r->sp -= 5;
            { const uint16_t sp_call = r->sp; JSL(c, 0xD3EB, 0xC00092); GUARD_JSL(c, sp_call, 0xD3EB); } /* run_native_dialogue_public_jump */
            r->sp += 5;
            uint16_t dp_ret = r->dp;
            uint8_t db_ret = r->db;
            bool m_ret = r->mf;
            bool x_ret = r->xf;
            uint16_t a_all = r->a;
            m_flag = m_ret;
            x_flag = x_ret;
            a1 = (uint8_t)a_all;
            a_hi1 = a_all >> 8;
            data_bank = db_ret;
            direct_page = dp_ret;
        }
        m_flag4 = m_flag;
        x_flag4 = x_flag;
        a4 = a1;
        a_hi4 = a_hi1;
        data_bank4 = data_bank;
        direct_page4 = direct_page;
    } else {
        uint8_t value3 = BUS8_RDP(c, (db << 0x10) + 0x1802);
        BUS8_SET(c, (db << 0x10) + 0x1802, value3 & 0xFB);
        uint8_t value4 = BUS8_RDP(c, (db << 0x10) + 0x1803);
        bool m_flag3;
        bool x_flag3;
        uint8_t a3;
        uint8_t a_hi3;
        uint8_t data_bank3;
        uint16_t direct_page3;
        if ((value4 & 0x10) != 0) {
            uint8_t value5 = BUS8_RDP(c, (db << 0x10) + 0x1D04);
            bool m_flag2;
            bool x_flag2;
            uint8_t a2;
            uint8_t a_hi2;
            uint8_t data_bank2;
            uint16_t direct_page2;
            if ((value5 & 1) == 0) {
                m_flag2 = 1;
                x_flag2 = 0;
                a2 = 1;
                a_hi2 = a_hi;
                data_bank2 = db;
                direct_page2 = dp;
            } else {
                BUS8_SET(c, (db << 0x10) + 0x1D13, 0);
                r->a = (a_hi << 8) | 1;
                r->z = (value5 & 1) == 0;
                r->n = value5 & 0x80;
                r->v = value5 & 0x40;
                r->sp -= 5;
                { const uint16_t sp_call = r->sp; JSL(c, 0xD3EB, 0xC00092); GUARD_JSL(c, sp_call, 0xD3EB); } /* run_native_dialogue_public_jump */
                r->sp += 5;
                uint16_t dp_ret2 = r->dp;
                uint8_t db_ret2 = r->db;
                bool m_ret2 = r->mf;
                bool x_ret3 = r->xf;
                uint16_t a_all2 = r->a;
                m_flag2 = m_ret2;
                x_flag2 = x_ret3;
                a2 = (uint8_t)a_all2;
                a_hi2 = a_all2 >> 8;
                data_bank2 = db_ret2;
                direct_page2 = dp_ret2;
            }
            m_flag3 = m_flag2;
            x_flag3 = x_flag2;
            a3 = a2;
            a_hi3 = a_hi2;
            data_bank3 = data_bank2;
            direct_page3 = direct_page2;
        } else {
            BUS16_SET(c, (db << 0x10) + 0x19D0, 0x527F);
            BUS16_SET(c, (db << 0x10) + 0x19D2, 0x55);
            BUS16_SET(c, (db << 0x10) + 0x19D4, 0);
            r->a = 0x55;
            r->mf = 0;
            r->sp -= 5;
            { const uint16_t sp_call = r->sp; JSL(c, 0xD3C1, 0xC06BE2); GUARD_JSL(c, sp_call, 0xD3C1); } /* calculate_wrapped_native_menu_row_index */
            r->sp += 5;
            uint16_t a_all3 = r->a;
            BUS8_SET(c, (db << 0x10) + 0x19D3, (uint8_t)a_all3);
            r->mf = 1;
            r->xf = 0;
            r->sp -= 5;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD3C9, 0xD0D3F0); GUARD_JSR(c, sp_call, 0xD3C9); } /* select_complete_native_menu_description_script */
            r->sp += 5;
            r->sp -= 5;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD3CC, 0xD0D5F3); GUARD_JSR(c, sp_call, 0xD3CC); } /* dispatch_native_menu_second_line_description */
            r->sp += 5;
            uint8_t db_ret3 = r->db;
            r->a = 0;
            r->x = 0x19D0;
            r->mf = 0;
            r->xf = 0;
            r->sp -= 5;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD3D7, 0xD0D5D7); GUARD_JSR(c, sp_call, 0xD3D7); } /* set_native_menu_dialogue_script_and_close_prior_window */
            r->sp += 5;
            BUS8_SET(c, (db_ret3 << 0x10) + 0x1D13, 0);
            r->mf = 1;
            r->xf = 0;
            r->sp -= 5;
            { const uint16_t sp_call = r->sp; JSL(c, 0xD3EB, 0xC00092); GUARD_JSL(c, sp_call, 0xD3EB); } /* run_native_dialogue_public_jump */
            r->sp += 5;
            uint16_t dp_ret4 = r->dp;
            uint8_t db_ret4 = r->db;
            bool m_ret5 = r->mf;
            bool x_ret10 = r->xf;
            uint16_t a_all7 = r->a;
            m_flag3 = m_ret5;
            x_flag3 = x_ret10;
            a3 = (uint8_t)a_all7;
            a_hi3 = a_all7 >> 8;
            data_bank3 = db_ret4;
            direct_page3 = dp_ret4;
        }
        m_flag4 = m_flag3;
        x_flag4 = x_flag3;
        a4 = a3;
        a_hi4 = a_hi3;
        data_bank4 = data_bank3;
        direct_page4 = direct_page3;
    }
    uint8_t value6 = RAM8(0x0000 + sp0 - 4);
    if (value6 & 0x10) {
        c->fail = 3;
        return;
    } else {
        uint8_t value9 = RAM8(0x0000 + sp0 - 3);
        uint8_t value10 = RAM8(0x0000 + sp0 - 2);
        uint8_t value11 = RAM8(0x0000 + sp0 - 1);
        uint8_t value12 = RAM8(0x0000 + sp0);
        r->a = (a_hi4 << 8) | a4;
        r->x = (value12 << 8) | value11;
        r->y = (value10 << 8) | value9;
        r->c = value6 & 0x01;
        r->z = ((value12 << 8) | value11) == 0;
        r->n = ((value12 << 8) | value11) & 0x8000;
        r->v = value6 & 0x40;
        r->mf = value6 & 0x20;
        r->xf = 0;
        r->db = data_bank4;
        r->dp = direct_page4;
        r->i = value6 & 0x04;
        r->d = value6 & 0x08;
        RETURN_RTL(c);
    }
}

/* D0D397 prepare_and_run_complete_native_menu_dialogue_frame   [class C, 89 bytes, 38 instructions]
 * Source: src/rom/prepare_and_run_complete_native_menu_dialogue_frame.s
 * Documented in docs/event-menu-text-tick.md
 * Entry: M=8 bit X=8 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void prepare_and_run_complete_native_menu_dialogue_frame_m8x8(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 1)) return;
    const uint16_t sp0 = r->sp + 2;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint8_t a_hi = r->a >> 8;
    const uint8_t x = r->x;
    const uint8_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    RAM8(0x0000 + sp0 - 2) = x;
    RAM8(0x0000 + sp0 - 3) = y;
    RAM8(0x0000 + sp0 - 4) = ((((negative << 7) | (overflow << 6) | 0x20 | 0x10) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    uint8_t value = BUS8_RDP(c, (db << 0x10) + 0x1802);
    bool m_flag4;
    bool x_flag4;
    uint8_t a4;
    uint8_t a_hi4;
    uint8_t data_bank4;
    uint16_t direct_page4;
    if ((value & 4) == 0) {
        uint8_t value2 = BUS8_RDP(c, (db << 0x10) + 0x1D04);
        bool m_flag;
        bool x_flag;
        uint8_t a1;
        uint8_t a_hi1;
        uint8_t data_bank;
        uint16_t direct_page;
        if ((value2 & 1) == 0) {
            m_flag = 1;
            x_flag = 1;
            a1 = 1;
            a_hi1 = a_hi;
            data_bank = db;
            direct_page = dp;
        } else {
            BUS8_SET(c, (db << 0x10) + 0x1D13, 0);
            r->a = (a_hi << 8) | 1;
            r->z = (value2 & 1) == 0;
            r->n = value2 & 0x80;
            r->v = value2 & 0x40;
            r->sp -= 3;
            { const uint16_t sp_call = r->sp; JSL(c, 0xD3EB, 0xC00092); GUARD_JSL(c, sp_call, 0xD3EB); } /* run_native_dialogue_public_jump */
            r->sp += 3;
            uint16_t dp_ret = r->dp;
            uint8_t db_ret = r->db;
            bool m_ret = r->mf;
            bool x_ret = r->xf;
            uint16_t a_all = r->a;
            m_flag = m_ret;
            x_flag = x_ret;
            a1 = (uint8_t)a_all;
            a_hi1 = a_all >> 8;
            data_bank = db_ret;
            direct_page = dp_ret;
        }
        m_flag4 = m_flag;
        x_flag4 = x_flag;
        a4 = a1;
        a_hi4 = a_hi1;
        data_bank4 = data_bank;
        direct_page4 = direct_page;
    } else {
        uint8_t value3 = BUS8_RDP(c, (db << 0x10) + 0x1802);
        BUS8_SET(c, (db << 0x10) + 0x1802, value3 & 0xFB);
        uint8_t value4 = BUS8_RDP(c, (db << 0x10) + 0x1803);
        bool m_flag3;
        bool x_flag3;
        uint8_t a3;
        uint8_t a_hi3;
        uint8_t data_bank3;
        uint16_t direct_page3;
        if ((value4 & 0x10) != 0) {
            uint8_t value5 = BUS8_RDP(c, (db << 0x10) + 0x1D04);
            bool m_flag2;
            bool x_flag2;
            uint8_t a2;
            uint8_t a_hi2;
            uint8_t data_bank2;
            uint16_t direct_page2;
            if ((value5 & 1) == 0) {
                m_flag2 = 1;
                x_flag2 = 1;
                a2 = 1;
                a_hi2 = a_hi;
                data_bank2 = db;
                direct_page2 = dp;
            } else {
                BUS8_SET(c, (db << 0x10) + 0x1D13, 0);
                r->a = (a_hi << 8) | 1;
                r->z = (value5 & 1) == 0;
                r->n = value5 & 0x80;
                r->v = value5 & 0x40;
                r->sp -= 3;
                { const uint16_t sp_call = r->sp; JSL(c, 0xD3EB, 0xC00092); GUARD_JSL(c, sp_call, 0xD3EB); } /* run_native_dialogue_public_jump */
                r->sp += 3;
                uint16_t dp_ret2 = r->dp;
                uint8_t db_ret2 = r->db;
                bool m_ret2 = r->mf;
                bool x_ret3 = r->xf;
                uint16_t a_all2 = r->a;
                m_flag2 = m_ret2;
                x_flag2 = x_ret3;
                a2 = (uint8_t)a_all2;
                a_hi2 = a_all2 >> 8;
                data_bank2 = db_ret2;
                direct_page2 = dp_ret2;
            }
            m_flag3 = m_flag2;
            x_flag3 = x_flag2;
            a3 = a2;
            a_hi3 = a_hi2;
            data_bank3 = data_bank2;
            direct_page3 = direct_page2;
        } else {
            BUS16_SET(c, (db << 0x10) + 0x19D0, 0x527F);
            BUS16_SET(c, (db << 0x10) + 0x19D2, 0x55);
            BUS16_SET(c, (db << 0x10) + 0x19D4, 0);
            r->a = 0x55;
            r->mf = 0;
            r->xf = 0;
            r->sp -= 3;
            { const uint16_t sp_call = r->sp; JSL(c, 0xD3C1, 0xC06BE2); GUARD_JSL(c, sp_call, 0xD3C1); } /* calculate_wrapped_native_menu_row_index */
            r->sp += 3;
            uint16_t a_all3 = r->a;
            BUS8_SET(c, (db << 0x10) + 0x19D3, (uint8_t)a_all3);
            r->mf = 1;
            r->xf = 0;
            r->sp -= 3;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD3C9, 0xD0D3F0); GUARD_JSR(c, sp_call, 0xD3C9); } /* select_complete_native_menu_description_script */
            r->sp += 3;
            r->sp -= 3;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD3CC, 0xD0D5F3); GUARD_JSR(c, sp_call, 0xD3CC); } /* dispatch_native_menu_second_line_description */
            r->sp += 3;
            uint8_t db_ret3 = r->db;
            r->a = 0;
            r->x = 0x19D0;
            r->mf = 0;
            r->xf = 0;
            r->sp -= 3;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD3D7, 0xD0D5D7); GUARD_JSR(c, sp_call, 0xD3D7); } /* set_native_menu_dialogue_script_and_close_prior_window */
            r->sp += 3;
            BUS8_SET(c, (db_ret3 << 0x10) + 0x1D13, 0);
            r->mf = 1;
            r->xf = 0;
            r->sp -= 3;
            { const uint16_t sp_call = r->sp; JSL(c, 0xD3EB, 0xC00092); GUARD_JSL(c, sp_call, 0xD3EB); } /* run_native_dialogue_public_jump */
            r->sp += 3;
            uint16_t dp_ret4 = r->dp;
            uint8_t db_ret4 = r->db;
            bool m_ret5 = r->mf;
            bool x_ret10 = r->xf;
            uint16_t a_all7 = r->a;
            m_flag3 = m_ret5;
            x_flag3 = x_ret10;
            a3 = (uint8_t)a_all7;
            a_hi3 = a_all7 >> 8;
            data_bank3 = db_ret4;
            direct_page3 = dp_ret4;
        }
        m_flag4 = m_flag3;
        x_flag4 = x_flag3;
        a4 = a3;
        a_hi4 = a_hi3;
        data_bank4 = data_bank3;
        direct_page4 = direct_page3;
    }
    uint8_t value6 = RAM8(0x0000 + sp0 - 4);
    if (value6 & 0x10) {
        uint8_t value7 = RAM8(0x0000 + sp0 - 3);
        uint8_t value8 = RAM8(0x0000 + sp0 - 2);
        r->a = (a_hi4 << 8) | a4;
        r->x = value8;
        r->y = value7;
        r->c = value6 & 0x01;
        r->z = value8 == 0;
        r->n = value8 & 0x80;
        r->v = value6 & 0x40;
        r->mf = value6 & 0x20;
        r->xf = 1;
        r->db = data_bank4;
        r->dp = direct_page4;
        r->i = value6 & 0x04;
        r->d = value6 & 0x08;
        RETURN_RTL(c);
    } else {
        uint8_t value9 = RAM8(0x0000 + sp0 - 3);
        uint8_t value10 = RAM8(0x0000 + sp0 - 2);
        uint8_t value11 = RAM8(0x0000 + sp0 - 1);
        uint8_t value12 = RAM8(0x0000 + sp0);
        r->a = (a_hi4 << 8) | a4;
        r->x = (value12 << 8) | value11;
        r->y = (value10 << 8) | value9;
        r->c = value6 & 0x01;
        r->z = ((value12 << 8) | value11) == 0;
        r->n = ((value12 << 8) | value11) & 0x8000;
        r->v = value6 & 0x40;
        r->mf = value6 & 0x20;
        r->xf = 0;
        r->db = data_bank4;
        r->dp = direct_page4;
        r->i = value6 & 0x04;
        r->d = value6 & 0x08;
        r->sp += 2;
        RETURN_RTL(c);
    }
}

/* Entered with M16/X16, M16/X8, M8/X16, M8/X8 accumulator/index widths: one body per width pair. */
static void prepare_and_run_complete_native_menu_dialogue_frame(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (r->mf == 0 && r->xf == 0) { prepare_and_run_complete_native_menu_dialogue_frame_m16x16(c); return; }
    if (r->mf == 0 && r->xf == 1) { prepare_and_run_complete_native_menu_dialogue_frame_m16x8(c); return; }
    if (r->mf == 1 && r->xf == 0) { prepare_and_run_complete_native_menu_dialogue_frame_m8x16(c); return; }
    if (r->mf == 1 && r->xf == 1) { prepare_and_run_complete_native_menu_dialogue_frame_m8x8(c); return; }
    c->fail = 3;
}
SOM_REGISTER(0xD0D397, SOM_RTL, "gen", prepare_and_run_complete_native_menu_dialogue_frame, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 5, -1, -1, 89, 38)
