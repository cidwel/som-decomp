#include "som_c.h"

/* 7ED3EA stop_native_title_main_resources_and_peer_tasks   [class B, 35 bytes, 19 instructions]
 * Source: src/boot/stop_native_title_main_resources_and_peer_tasks.s
 * Documented in docs/source-recovery-parallel-main-stopped-callback.md
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void stop_native_title_main_resources_and_peer_tasks(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = db;
    RAM8(0x0000 + sp0 - 4) = 0x7F;
    uint16_t value = RAM16(0x1030E);
    bool m_flag;
    bool x_flag;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool carry1;
    bool overflow1;
    uint8_t data_bank;
    uint16_t direct_page;
    if (value == 0) {
        m_flag = 1;
        x_flag = 0;
        a_hi1 = a_hi;
        x1 = value;
        y1 = y;
        carry1 = carry;
        overflow1 = overflow;
        data_bank = 0x7F;
        direct_page = dp;
    } else {
        r->z = value == 0;
        r->n = value & 0x8000;
        r->db = 0x7F;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD3FC, 0x7ED3AA); GUARD_JSR(c, sp_call, 0xD3FC); } /* teardown_title_window_and_tracked_tasks */
        r->sp += 4;
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        bool m_ret = r->mf;
        bool x_ret = r->xf;
        uint16_t a_all = r->a;
        uint16_t x_ret2 = r->x;
        uint16_t y_ret = r->y;
        bool carry_ret = r->c;
        bool overflow_ret = r->v;
        m_flag = m_ret;
        x_flag = x_ret;
        a_hi1 = a_all >> 8;
        x1 = x_ret2;
        y1 = y_ret;
        carry1 = carry_ret;
        overflow1 = overflow_ret;
        data_bank = db_ret;
        direct_page = dp_ret;
    }
    if (m_flag) {
        uint8_t value2 = BUS8_RDP(c, (data_bank << 0x10) + 0x0312);
        r->a = (a_hi1 << 8) | value2;
        r->x = x1;
        r->y = y1;
        r->c = carry1;
        r->z = value2 == 0;
        r->n = value2 & 0x80;
        r->v = overflow1;
        r->mf = 1;
        r->xf = x_flag;
        r->db = data_bank;
        r->dp = direct_page;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD402, 0x7EACAC); GUARD_JSR(c, sp_call, 0xD402); } /* request_task_stop_by_id */
        r->sp += 4;
        uint8_t db_ret2 = r->db;
        bool m_ret2 = r->mf;
        uint16_t a_all2 = r->a;
        if (m_ret2) {
            uint8_t value3 = BUS8_RDP(c, (db_ret2 << 0x10) + 0x0311);
            r->a = (a_all2 >> 8 << 8) | value3;
            r->z = value3 == 0;
            r->n = value3 & 0x80;
            r->mf = 1;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD408, 0x7EACAC); GUARD_JSR(c, sp_call, 0xD408); } /* request_task_stop_by_id */
            r->sp += 4;
            uint8_t value4 = RAM8(0x0000 + sp0 - 3);
            uint8_t value5 = RAM8(0x0000 + sp0 - 2);
            uint8_t value6 = RAM8(0x0000 + sp0 - 1);
            uint8_t value7 = RAM8(0x0000 + sp0);
            r->c = value5 & 0x01;
            r->z = ((value7 << 8) | value6) == 0;
            r->n = ((value7 << 8) | value6) & 0x8000;
            r->v = value5 & 0x40;
            r->mf = value5 & 0x20;
            r->xf = value5 & 0x10;
            r->db = value4;
            r->dp = (value7 << 8) | value6;
            r->i = value5 & 0x04;
            r->d = value5 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTL(c);
        } else {
            uint16_t value8 = BUS16_RDP(c, (db_ret2 << 0x10) + 0x0311);
            r->a = value8;
            r->z = value8 == 0;
            r->n = value8 & 0x8000;
            r->mf = 0;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD408, 0x7EACAC); GUARD_JSR(c, sp_call, 0xD408); } /* request_task_stop_by_id */
            r->sp += 4;
            uint8_t value9 = RAM8(0x0000 + sp0 - 3);
            uint8_t value10 = RAM8(0x0000 + sp0 - 2);
            uint8_t value11 = RAM8(0x0000 + sp0 - 1);
            uint8_t value12 = RAM8(0x0000 + sp0);
            r->c = value10 & 0x01;
            r->z = ((value12 << 8) | value11) == 0;
            r->n = ((value12 << 8) | value11) & 0x8000;
            r->v = value10 & 0x40;
            r->mf = value10 & 0x20;
            r->xf = value10 & 0x10;
            r->db = value9;
            r->dp = (value12 << 8) | value11;
            r->i = value10 & 0x04;
            r->d = value10 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTL(c);
        }
    } else {
        uint16_t value13 = BUS16_RDP(c, (data_bank << 0x10) + 0x0312);
        r->a = value13;
        r->x = x1;
        r->y = y1;
        r->c = carry1;
        r->z = value13 == 0;
        r->n = value13 & 0x8000;
        r->v = overflow1;
        r->mf = 0;
        r->xf = x_flag;
        r->db = data_bank;
        r->dp = direct_page;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD402, 0x7EACAC); GUARD_JSR(c, sp_call, 0xD402); } /* request_task_stop_by_id */
        r->sp += 4;
        uint8_t db_ret5 = r->db;
        bool m_ret5 = r->mf;
        uint16_t a_all5 = r->a;
        if (m_ret5) {
            uint8_t value14 = BUS8_RDP(c, (db_ret5 << 0x10) + 0x0311);
            r->a = (a_all5 >> 8 << 8) | value14;
            r->z = value14 == 0;
            r->n = value14 & 0x80;
            r->mf = 1;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD408, 0x7EACAC); GUARD_JSR(c, sp_call, 0xD408); } /* request_task_stop_by_id */
            r->sp += 4;
            uint8_t value15 = RAM8(0x0000 + sp0 - 3);
            uint8_t value16 = RAM8(0x0000 + sp0 - 2);
            uint8_t value17 = RAM8(0x0000 + sp0 - 1);
            uint8_t value18 = RAM8(0x0000 + sp0);
            r->c = value16 & 0x01;
            r->z = ((value18 << 8) | value17) == 0;
            r->n = ((value18 << 8) | value17) & 0x8000;
            r->v = value16 & 0x40;
            r->mf = value16 & 0x20;
            r->xf = value16 & 0x10;
            r->db = value15;
            r->dp = (value18 << 8) | value17;
            r->i = value16 & 0x04;
            r->d = value16 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTL(c);
        } else {
            uint16_t value19 = BUS16_RDP(c, (db_ret5 << 0x10) + 0x0311);
            r->a = value19;
            r->z = value19 == 0;
            r->n = value19 & 0x8000;
            r->mf = 0;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD408, 0x7EACAC); GUARD_JSR(c, sp_call, 0xD408); } /* request_task_stop_by_id */
            r->sp += 4;
            uint8_t value20 = RAM8(0x0000 + sp0 - 3);
            uint8_t value21 = RAM8(0x0000 + sp0 - 2);
            uint8_t value22 = RAM8(0x0000 + sp0 - 1);
            uint8_t value23 = RAM8(0x0000 + sp0);
            r->c = value21 & 0x01;
            r->z = ((value23 << 8) | value22) == 0;
            r->n = ((value23 << 8) | value22) & 0x8000;
            r->v = value21 & 0x40;
            r->mf = value21 & 0x20;
            r->xf = value21 & 0x10;
            r->db = value20;
            r->dp = (value23 << 8) | value22;
            r->i = value21 & 0x04;
            r->d = value21 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTL(c);
        }
    }
}
SOM_REGISTER(0x7ED3EA, SOM_RTL, "gen", stop_native_title_main_resources_and_peer_tasks, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 5, 1, 0, 35, 19)
