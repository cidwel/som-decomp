#include "som_c.h"

/* 7ED3AA teardown_title_window_and_tracked_tasks   [class B, 64 bytes, 32 instructions]
 * Source: src/boot/teardown_title_window_and_tracked_tasks.s
 * Entry: M=8 bit X=16 bit DB=$7F D=$02EE.  Callers read: ABXYCV.
 */
static void teardown_title_window_and_tracked_tasks(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x02EE) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    uint8_t a_hi_d3d6 = 0;
    uint16_t x_d3d6 = 0;
    uint16_t y_d3d6 = 0;
    bool carry_d3d6 = 0;
    bool overflow_d3d6 = 0;
    uint16_t direct_page_d3d6 = 0;
    uint8_t data_bank_d3d6 = 0;
    uint8_t a_hi_d3d62 = 0;
    uint8_t x_d3d62 = 0;
    uint8_t y_d3d62 = 0;
    bool carry_d3d62 = 0;
    bool overflow_d3d62 = 0;
    uint16_t direct_page_d3d62 = 0;
    uint8_t data_bank_d3d62 = 0;
    uint8_t a_hi_d3d63 = 0;
    uint8_t x_d3d63 = 0;
    uint8_t y_d3d63 = 0;
    bool carry_d3d63 = 0;
    bool overflow_d3d63 = 0;
    uint16_t direct_page_d3d63 = 0;
    uint8_t data_bank_d3d63 = 0;
    uint8_t a_hi_d3d64 = 0;
    uint16_t x_d3d64 = 0;
    uint16_t y_d3d64 = 0;
    bool carry_d3d64 = 0;
    bool overflow_d3d64 = 0;
    uint16_t direct_page_d3d64 = 0;
    uint8_t data_bank_d3d64 = 0;
    RAM8(0x0000 + sp0) = 2;
    RAM8(0x0000 + sp0 - 1) = 0xEE;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7F;
    uint16_t value = RAM16(0x1030E);
    r->a = (uint16_t)(sp0 - 4);
    r->x = value;
    r->z = value == 0;
    r->n = value & 0x8000;
    r->dp = (uint16_t)(sp0 - 4);
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD3B8, 0x7E9066); GUARD_JSR(c, sp_call, 0xD3B8); } /* release_transfer_descriptor */
    r->sp += 4;
    uint8_t db_ret = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    uint16_t a_all = r->a;
    BUS8_SET(c, (db_ret << 0x10) + 0x030E, 0);
    BUS8_SET(c, (db_ret << 0x10) + 0x030F, 0);
    r->a = (a_all >> 8 << 8) | 0x2C;
    r->z = 0;
    r->n = 0;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD3C3, 0x7EC030); GUARD_JSR(c, sp_call, 0xD3C3); } /* allocate_ppu_register_entry */
    r->sp += 4;
    uint8_t db_ret2 = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    uint16_t a_all2 = r->a;
    uint16_t x_ret4 = r->x;
    uint8_t value2 = BUS8_RDP(c, (db_ret2 << 0x10) + 2 + x_ret4);
    BUS8_SET(c, (db_ret2 << 0x10) + 2 + x_ret4, value2 & 0xFE);
    r->a = a_all2 >> 8 << 8 | (value2 & 0xFE);
    r->z = (value2 & 0xFE) == 0;
    r->n = value2 & 0xFE & 0x80;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD3CE, 0x7EC097); GUARD_JSR(c, sp_call, 0xD3CE); } /* append_oneshot_ppu_entry */
    r->sp += 4;
    uint16_t dp_ret3 = r->dp;
    uint8_t db_ret3 = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all3 = r->a;
    uint16_t y_ret3 = r->y;
    bool carry_ret3 = r->c;
    bool overflow_ret3 = r->v;
    BUS8_SET(c, (uint16_t)(dp_ret3 + 1), 0x14);
    a_hi_d3d6 = a_all3 >> 8;
    x_d3d6 = 0x0318;
    y_d3d6 = y_ret3;
    carry_d3d6 = carry_ret3;
    overflow_d3d6 = overflow_ret3;
    direct_page_d3d6 = dp_ret3;
    data_bank_d3d6 = db_ret3;
    shared_D3D6:;
    RAM8(0x0000 + sp0 - 4) = x_d3d6 >> 8;
    RAM8(0x0000 + sp0 - 5) = (uint8_t)x_d3d6;
    uint8_t value3 = BUS8_RDP(c, (data_bank_d3d6 << 0x10) + x_d3d6);
    r->a = (a_hi_d3d6 << 8) | value3;
    r->x = x_d3d6;
    r->y = y_d3d6;
    r->c = carry_d3d6;
    r->z = value3 == 0;
    r->n = value3 & 0x80;
    r->v = overflow_d3d6;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_d3d6;
    r->dp = direct_page_d3d6;
    r->sp -= 6;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD3DC, 0x7EACAC); GUARD_JSR(c, sp_call, 0xD3DC); } /* request_task_stop_by_id */
    r->sp += 6;
    uint16_t dp_ret4 = r->dp;
    uint8_t db_ret4 = r->db;
    bool m_ret = r->mf;
    bool x_ret5 = r->xf;
    uint16_t a_all4 = r->a;
    uint16_t y_ret4 = r->y;
    bool carry_ret4 = r->c;
    bool overflow_ret4 = r->v;
    if (x_ret5) {
        uint8_t value4 = RAM8(0x0000 + sp0 - 5);
        if (m_ret) {
            c->fail = 3;
            return;
        } else {
            BUS16_SET(c, (db_ret4 << 0x10) + value4, 0);
            uint16_t value10 = BUS16_RDP(c, (uint16_t)(dp_ret4 + 1));
            BUS16_RMW_SET(c, (uint16_t)(dp_ret4 + 1), (uint16_t)(value10 - 1));
            if ((uint16_t)(value10 - 1) != 0) {
                a_hi_d3d63 = a_all4 >> 8;
                x_d3d63 = (uint8_t)(value4 + 1);
                y_d3d63 = (uint8_t)y_ret4;
                carry_d3d63 = carry_ret4;
                overflow_d3d63 = overflow_ret4;
                direct_page_d3d63 = dp_ret4;
                data_bank_d3d63 = db_ret4;
                goto shared_D3D6_2;
            }
            uint8_t value11 = RAM8(0x0000 + sp0 - 4);
            uint8_t value12 = RAM8(0x0000 + sp0 - 3);
            uint8_t value13 = RAM8(0x0000 + sp0 - 2);
            uint8_t value14 = RAM8(0x0000 + sp0 - 1);
            uint8_t value15 = RAM8(0x0000 + sp0);
            r->a = (value12 << 8) | value11;
            r->x = (uint8_t)(value4 + 1);
            r->y = (uint8_t)y_ret4;
            r->c = value13 & 0x01;
            r->v = value13 & 0x40;
            r->mf = value13 & 0x20;
            r->xf = value13 & 0x10;
            r->dp = (value15 << 8) | value14;
            r->i = value13 & 0x04;
            r->d = value13 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
    } else {
        uint8_t value16 = RAM8(0x0000 + sp0 - 5);
        uint8_t value17 = RAM8(0x0000 + sp0 - 4);
        if (m_ret) {
            BUS8_SET(c, (db_ret4 << 0x10) + ((value17 << 8) | value16), 0);
            uint8_t value18 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 1));
            BUS8_SET(c, (uint16_t)(dp_ret4 + 1), (uint8_t)(value18 - 1));
            if ((uint8_t)(value18 - 1) != 0) {
                a_hi_d3d6 = a_all4 >> 8;
                x_d3d6 = (uint16_t)(((value17 << 8) | value16) + 1);
                y_d3d6 = y_ret4;
                carry_d3d6 = carry_ret4;
                overflow_d3d6 = overflow_ret4;
                direct_page_d3d6 = dp_ret4;
                data_bank_d3d6 = db_ret4;
                goto shared_D3D6;
            }
            uint8_t value19 = RAM8(0x0000 + sp0 - 3);
            uint8_t value20 = RAM8(0x0000 + sp0 - 2);
            uint8_t value21 = RAM8(0x0000 + sp0 - 1);
            uint8_t value22 = RAM8(0x0000 + sp0);
            r->a = (a_all4 >> 8 << 8) | value19;
            r->x = (uint16_t)(((value17 << 8) | value16) + 1);
            r->c = value20 & 0x01;
            r->v = value20 & 0x40;
            r->mf = value20 & 0x20;
            r->xf = value20 & 0x10;
            r->dp = (value22 << 8) | value21;
            r->i = value20 & 0x04;
            r->d = value20 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        } else {
            c->fail = 3;
            return;
        }
    }
    shared_D3D6_1:;
    RAM8(0x0000 + sp0 - 5) = x_d3d62;
    uint8_t value27 = BUS8_RDP(c, (data_bank_d3d62 << 0x10) + x_d3d62);
    r->a = (a_hi_d3d62 << 8) | value27;
    r->x = x_d3d62;
    r->y = y_d3d62;
    r->c = carry_d3d62;
    r->z = value27 == 0;
    r->n = value27 & 0x80;
    r->v = overflow_d3d62;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_d3d62;
    r->dp = direct_page_d3d62;
    r->sp -= 6;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD3DC, 0x7EACAC); GUARD_JSR(c, sp_call, 0xD3DC); } /* request_task_stop_by_id */
    r->sp += 6;
    uint16_t dp_ret5 = r->dp;
    uint8_t db_ret5 = r->db;
    bool m_ret2 = r->mf;
    bool x_ret7 = r->xf;
    uint16_t a_all5 = r->a;
    uint16_t y_ret5 = r->y;
    bool carry_ret5 = r->c;
    bool overflow_ret5 = r->v;
    if (x_ret7) {
        uint8_t value28 = RAM8(0x0000 + sp0 - 5);
        if (m_ret2) {
            c->fail = 3;
            return;
        } else {
            BUS16_SET(c, (db_ret5 << 0x10) + value28, 0);
            uint16_t value34 = BUS16_RDP(c, (uint16_t)(dp_ret5 + 1));
            BUS16_RMW_SET(c, (uint16_t)(dp_ret5 + 1), (uint16_t)(value34 - 1));
            if ((uint16_t)(value34 - 1) != 0) {
                a_hi_d3d63 = a_all5 >> 8;
                x_d3d63 = (uint8_t)(value28 + 1);
                y_d3d63 = (uint8_t)y_ret5;
                carry_d3d63 = carry_ret5;
                overflow_d3d63 = overflow_ret5;
                direct_page_d3d63 = dp_ret5;
                data_bank_d3d63 = db_ret5;
                goto shared_D3D6_2;
            }
            uint8_t value35 = RAM8(0x0000 + sp0 - 4);
            uint8_t value36 = RAM8(0x0000 + sp0 - 3);
            uint8_t value37 = RAM8(0x0000 + sp0 - 2);
            uint8_t value38 = RAM8(0x0000 + sp0 - 1);
            uint8_t value39 = RAM8(0x0000 + sp0);
            r->a = (value36 << 8) | value35;
            r->x = (uint8_t)(value28 + 1);
            r->y = (uint8_t)y_ret5;
            r->c = value37 & 0x01;
            r->v = value37 & 0x40;
            r->mf = value37 & 0x20;
            r->xf = value37 & 0x10;
            r->dp = (value39 << 8) | value38;
            r->i = value37 & 0x04;
            r->d = value37 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
    } else {
        uint8_t value40 = RAM8(0x0000 + sp0 - 5);
        uint8_t value41 = RAM8(0x0000 + sp0 - 4);
        if (m_ret2) {
            BUS8_SET(c, (db_ret5 << 0x10) + ((value41 << 8) | value40), 0);
            uint8_t value42 = BUS8_RDP(c, (uint16_t)(dp_ret5 + 1));
            BUS8_SET(c, (uint16_t)(dp_ret5 + 1), (uint8_t)(value42 - 1));
            if ((uint8_t)(value42 - 1) != 0) {
                a_hi_d3d6 = a_all5 >> 8;
                x_d3d6 = (uint16_t)(((value41 << 8) | value40) + 1);
                y_d3d6 = y_ret5;
                carry_d3d6 = carry_ret5;
                overflow_d3d6 = overflow_ret5;
                direct_page_d3d6 = dp_ret5;
                data_bank_d3d6 = db_ret5;
                goto shared_D3D6;
            }
            uint8_t value43 = RAM8(0x0000 + sp0 - 3);
            uint8_t value44 = RAM8(0x0000 + sp0 - 2);
            uint8_t value45 = RAM8(0x0000 + sp0 - 1);
            uint8_t value46 = RAM8(0x0000 + sp0);
            r->a = (a_all5 >> 8 << 8) | value43;
            r->x = (uint16_t)(((value41 << 8) | value40) + 1);
            r->c = value44 & 0x01;
            r->v = value44 & 0x40;
            r->mf = value44 & 0x20;
            r->xf = value44 & 0x10;
            r->dp = (value46 << 8) | value45;
            r->i = value44 & 0x04;
            r->d = value44 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        } else {
            c->fail = 3;
            return;
        }
    }
    shared_D3D6_2:;
    RAM8(0x0000 + sp0 - 5) = x_d3d63;
    uint16_t value51 = BUS16_RDP(c, (data_bank_d3d63 << 0x10) + x_d3d63);
    r->a = value51;
    r->x = x_d3d63;
    r->y = y_d3d63;
    r->c = carry_d3d63;
    r->z = value51 == 0;
    r->n = value51 & 0x8000;
    r->v = overflow_d3d63;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_d3d63;
    r->dp = direct_page_d3d63;
    r->sp -= 6;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD3DC, 0x7EACAC); GUARD_JSR(c, sp_call, 0xD3DC); } /* request_task_stop_by_id */
    r->sp += 6;
    uint16_t dp_ret6 = r->dp;
    uint8_t db_ret6 = r->db;
    bool m_ret3 = r->mf;
    bool x_ret9 = r->xf;
    uint16_t a_all6 = r->a;
    uint16_t y_ret6 = r->y;
    bool carry_ret6 = r->c;
    bool overflow_ret6 = r->v;
    if (x_ret9) {
        uint8_t value52 = RAM8(0x0000 + sp0 - 5);
        if (m_ret3) {
            c->fail = 3;
            return;
        } else {
            BUS16_SET(c, (db_ret6 << 0x10) + value52, 0);
            uint16_t value58 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 1));
            BUS16_RMW_SET(c, (uint16_t)(dp_ret6 + 1), (uint16_t)(value58 - 1));
            if ((uint16_t)(value58 - 1) != 0) {
                a_hi_d3d63 = a_all6 >> 8;
                x_d3d63 = (uint8_t)(value52 + 1);
                y_d3d63 = (uint8_t)y_ret6;
                carry_d3d63 = carry_ret6;
                overflow_d3d63 = overflow_ret6;
                direct_page_d3d63 = dp_ret6;
                data_bank_d3d63 = db_ret6;
                goto shared_D3D6_2;
            }
            uint8_t value59 = RAM8(0x0000 + sp0 - 4);
            uint8_t value60 = RAM8(0x0000 + sp0 - 3);
            uint8_t value61 = RAM8(0x0000 + sp0 - 2);
            uint8_t value62 = RAM8(0x0000 + sp0 - 1);
            uint8_t value63 = RAM8(0x0000 + sp0);
            r->a = (value60 << 8) | value59;
            r->x = (uint8_t)(value52 + 1);
            r->y = (uint8_t)y_ret6;
            r->c = value61 & 0x01;
            r->v = value61 & 0x40;
            r->mf = value61 & 0x20;
            r->xf = value61 & 0x10;
            r->dp = (value63 << 8) | value62;
            r->i = value61 & 0x04;
            r->d = value61 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
    } else {
        uint8_t value64 = RAM8(0x0000 + sp0 - 5);
        uint8_t value65 = RAM8(0x0000 + sp0 - 4);
        if (m_ret3) {
            BUS8_SET(c, (db_ret6 << 0x10) + ((value65 << 8) | value64), 0);
            uint8_t value66 = BUS8_RDP(c, (uint16_t)(dp_ret6 + 1));
            BUS8_SET(c, (uint16_t)(dp_ret6 + 1), (uint8_t)(value66 - 1));
            if ((uint8_t)(value66 - 1) != 0) {
                a_hi_d3d6 = a_all6 >> 8;
                x_d3d6 = (uint16_t)(((value65 << 8) | value64) + 1);
                y_d3d6 = y_ret6;
                carry_d3d6 = carry_ret6;
                overflow_d3d6 = overflow_ret6;
                direct_page_d3d6 = dp_ret6;
                data_bank_d3d6 = db_ret6;
                goto shared_D3D6;
            }
            uint8_t value67 = RAM8(0x0000 + sp0 - 3);
            uint8_t value68 = RAM8(0x0000 + sp0 - 2);
            uint8_t value69 = RAM8(0x0000 + sp0 - 1);
            uint8_t value70 = RAM8(0x0000 + sp0);
            r->a = (a_all6 >> 8 << 8) | value67;
            r->x = (uint16_t)(((value65 << 8) | value64) + 1);
            r->c = value68 & 0x01;
            r->v = value68 & 0x40;
            r->mf = value68 & 0x20;
            r->xf = value68 & 0x10;
            r->dp = (value70 << 8) | value69;
            r->i = value68 & 0x04;
            r->d = value68 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        } else {
            c->fail = 3;
            return;
        }
    }
    shared_D3D6_3:;
    RAM8(0x0000 + sp0 - 4) = x_d3d64 >> 8;
    RAM8(0x0000 + sp0 - 5) = (uint8_t)x_d3d64;
    uint16_t value75 = BUS16_RDP(c, (data_bank_d3d64 << 0x10) + x_d3d64);
    r->a = value75;
    r->x = x_d3d64;
    r->y = y_d3d64;
    r->c = carry_d3d64;
    r->z = value75 == 0;
    r->n = value75 & 0x8000;
    r->v = overflow_d3d64;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_d3d64;
    r->dp = direct_page_d3d64;
    r->sp -= 6;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD3DC, 0x7EACAC); GUARD_JSR(c, sp_call, 0xD3DC); } /* request_task_stop_by_id */
    r->sp += 6;
    uint16_t dp_ret7 = r->dp;
    uint8_t db_ret7 = r->db;
    bool m_ret4 = r->mf;
    bool x_ret11 = r->xf;
    uint16_t a_all7 = r->a;
    uint16_t y_ret7 = r->y;
    bool carry_ret7 = r->c;
    bool overflow_ret7 = r->v;
    if (x_ret11) {
        uint8_t value76 = RAM8(0x0000 + sp0 - 5);
        if (m_ret4) {
            c->fail = 3;
            return;
        } else {
            BUS16_SET(c, (db_ret7 << 0x10) + value76, 0);
            uint16_t value82 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 1));
            BUS16_RMW_SET(c, (uint16_t)(dp_ret7 + 1), (uint16_t)(value82 - 1));
            if ((uint16_t)(value82 - 1) != 0) {
                a_hi_d3d63 = a_all7 >> 8;
                x_d3d63 = (uint8_t)(value76 + 1);
                y_d3d63 = (uint8_t)y_ret7;
                carry_d3d63 = carry_ret7;
                overflow_d3d63 = overflow_ret7;
                direct_page_d3d63 = dp_ret7;
                data_bank_d3d63 = db_ret7;
                goto shared_D3D6_2;
            }
            uint8_t value83 = RAM8(0x0000 + sp0 - 4);
            uint8_t value84 = RAM8(0x0000 + sp0 - 3);
            uint8_t value85 = RAM8(0x0000 + sp0 - 2);
            uint8_t value86 = RAM8(0x0000 + sp0 - 1);
            uint8_t value87 = RAM8(0x0000 + sp0);
            r->a = (value84 << 8) | value83;
            r->x = (uint8_t)(value76 + 1);
            r->y = (uint8_t)y_ret7;
            r->c = value85 & 0x01;
            r->v = value85 & 0x40;
            r->mf = value85 & 0x20;
            r->xf = value85 & 0x10;
            r->dp = (value87 << 8) | value86;
            r->i = value85 & 0x04;
            r->d = value85 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
    } else {
        uint8_t value88 = RAM8(0x0000 + sp0 - 5);
        uint8_t value89 = RAM8(0x0000 + sp0 - 4);
        if (m_ret4) {
            BUS8_SET(c, (db_ret7 << 0x10) + ((value89 << 8) | value88), 0);
            uint8_t value90 = BUS8_RDP(c, (uint16_t)(dp_ret7 + 1));
            BUS8_SET(c, (uint16_t)(dp_ret7 + 1), (uint8_t)(value90 - 1));
            if ((uint8_t)(value90 - 1) != 0) {
                a_hi_d3d6 = a_all7 >> 8;
                x_d3d6 = (uint16_t)(((value89 << 8) | value88) + 1);
                y_d3d6 = y_ret7;
                carry_d3d6 = carry_ret7;
                overflow_d3d6 = overflow_ret7;
                direct_page_d3d6 = dp_ret7;
                data_bank_d3d6 = db_ret7;
                goto shared_D3D6;
            }
            uint8_t value91 = RAM8(0x0000 + sp0 - 3);
            uint8_t value92 = RAM8(0x0000 + sp0 - 2);
            uint8_t value93 = RAM8(0x0000 + sp0 - 1);
            uint8_t value94 = RAM8(0x0000 + sp0);
            r->a = (a_all7 >> 8 << 8) | value91;
            r->x = (uint16_t)(((value89 << 8) | value88) + 1);
            r->c = value92 & 0x01;
            r->v = value92 & 0x40;
            r->mf = value92 & 0x20;
            r->xf = value92 & 0x10;
            r->dp = (value94 << 8) | value93;
            r->i = value92 & 0x04;
            r->d = value92 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        } else {
            c->fail = 3;
            return;
        }
    }
}
SOM_REGISTER(0x7ED3AA, SOM_RTS, "gen", teardown_title_window_and_tracked_tasks, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 6, 1, 0, 64, 32)
