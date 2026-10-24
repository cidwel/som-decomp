#include "som_c.h"

/* 7EB2AB prepend_pending_record   [class B, 80 bytes, 47 instructions]
 * Source: src/boot/prepend_pending_record.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: nothing.
 */
static void prepend_pending_record(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 5) + 0x2 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a_hi;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)((a_hi << 8) | a);
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    RAM8(0x0000 + sp0 - 5) = 0x7E;
    RAM8(0x0000 + sp0 - 6) = (uint8_t)((a_hi << 8) | a);
    RAM8(0x0000 + sp0 - 7) = 0x7F;
    RAM8(0x0000 + sp0 - 6) = (((((uint8_t)((a_hi << 8) | a) >> 7 << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (((uint8_t)((a_hi << 8) | a) == 0) << 1) | carry;
    BUS16_SET(c, 0x7F0000 + x, 0);
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 5), x);
    r->a = (a_hi << 8) | a;
    r->z = (uint8_t)((a_hi << 8) | a) == 0;
    r->n = (uint8_t)((a_hi << 8) | a) & 0x80;
    r->mf = 0;
    r->db = 0x7F;
    r->dp = (uint16_t)(sp0 - 5);
    r->i = 1;
    r->sp -= 7;
    { const uint16_t sp_call = r->sp; JSR(c, 0xB2C8, 0x7EAD02); GUARD_JSR(c, sp_call, 0xB2C8); } /* find_task_by_id */
    r->sp += 7;
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    bool m_ret = r->mf;
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    if (m_ret) {
        bool m_flag;
        bool x_flag2;
        uint8_t a1;
        uint8_t a_hi1;
        uint8_t data_bank2;
        uint16_t direct_page2;
        if ((uint8_t)x_ret == 0) {
            m_flag = 1;
            x_flag2 = 0;
            a1 = (uint8_t)x_ret;
            a_hi1 = a_all >> 8;
            data_bank2 = db_ret;
            direct_page2 = dp_ret;
        } else {
            uint16_t value = BUS16_RDP(c, (db_ret << 0x10) + 0x0A + x_ret);
            bool x_flag;
            uint8_t data_bank;
            uint16_t direct_page;
            if (value == 0) {
                uint8_t value2 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
                BUS8_SET(c, (db_ret << 0x10) + 0x0A + x_ret, value2);
                r->a = (a_all >> 8 << 8) | value2;
                r->y = value;
                r->z = value2 == 0;
                r->n = value2 & 0x80;
                r->mf = 1;
                r->sp -= 7;
                { const uint16_t sp_call = r->sp; JSR(c, 0xB2DD, 0x7EAC69); GUARD_JSR(c, sp_call, 0xB2DD); } /* wake_waiting_task */
                r->sp += 7;
                uint16_t dp_ret2 = r->dp;
                uint8_t db_ret2 = r->db;
                if (r->mf != 0) { c->fail = 3; return; }
                bool x_ret2 = r->xf;
                x_flag = x_ret2;
                data_bank = db_ret2;
                direct_page = dp_ret2;
            } else {
                if (value != 0xFFFF) {
                    uint8_t value3 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
                    BUS8_SET(c, (db_ret << 0x10) + 0x0A + x_ret, value3);
                    BUS8_SET(c, (db_ret << 0x10) + ((a_all >> 8 << 8) | value3), (uint8_t)value);
                    c->fail = 3; /* operand size does not fit the register width on this path */
                    return;
                }
                uint8_t value4 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
                BUS8_SET(c, (db_ret << 0x10) + 0x0A + x_ret, value4);
                r->a = (a_all >> 8 << 8) | value4;
                r->y = value;
                r->c = value >= 0xFFFF;
                r->z = value4 == 0;
                r->n = value4 & 0x80;
                r->mf = 1;
                r->sp -= 7;
                { const uint16_t sp_call = r->sp; JSR(c, 0xB2DD, 0x7EAC69); GUARD_JSR(c, sp_call, 0xB2DD); } /* wake_waiting_task */
                r->sp += 7;
                uint16_t dp_ret3 = r->dp;
                uint8_t db_ret3 = r->db;
                if (r->mf != 0) { c->fail = 3; return; }
                bool x_ret4 = r->xf;
                x_flag = x_ret4;
                data_bank = db_ret3;
                direct_page = dp_ret3;
            }
            m_flag = 0;
            x_flag2 = x_flag;
            a1 = 0xFF;
            a_hi1 = 0xFF;
            data_bank2 = data_bank;
            direct_page2 = direct_page;
        }
        uint8_t value6 = RAM8(0x0000 + sp0 - 5);
        RAM8(0x0000 + sp0 - 3) = a1;
        uint8_t value9 = RAM8(0x0000 + sp0 - 2);
        uint8_t value10 = RAM8(0x0000 + sp0 - 1);
        uint8_t value11 = RAM8(0x0000 + sp0);
        r->mf = value9 & 0x20;
        r->xf = value9 & 0x10;
        r->db = value6;
        r->dp = (value11 << 8) | value10;
        r->i = value9 & 0x04;
        r->d = value9 & 0x08;
        RETURN_RTS(c);
    } else {
        bool x_flag5;
        uint8_t a2;
        uint8_t a_hi2;
        uint8_t data_bank5;
        uint16_t direct_page5;
        if (x_ret == 0) {
            x_flag5 = 0;
            a2 = (uint8_t)x_ret;
            a_hi2 = x_ret >> 8;
            data_bank5 = db_ret;
            direct_page5 = dp_ret;
        } else {
            uint16_t value12 = BUS16_RDP(c, (db_ret << 0x10) + 0x0A + x_ret);
            bool x_flag4;
            uint8_t data_bank4;
            uint16_t direct_page4;
            if (value12 == 0) {
                uint16_t value13 = BUS16_RDP(c, (uint16_t)(dp_ret + 1));
                BUS16_SET(c, (db_ret << 0x10) + 0x0A + x_ret, value13);
                r->a = value13;
                r->y = value12;
                r->z = value13 == 0;
                r->n = value13 & 0x8000;
                r->mf = 0;
                r->sp -= 7;
                { const uint16_t sp_call = r->sp; JSR(c, 0xB2DD, 0x7EAC69); GUARD_JSR(c, sp_call, 0xB2DD); } /* wake_waiting_task */
                r->sp += 7;
                uint16_t dp_ret4 = r->dp;
                uint8_t db_ret4 = r->db;
                if (r->mf != 0) { c->fail = 3; return; }
                bool x_ret6 = r->xf;
                x_flag4 = x_ret6;
                data_bank4 = db_ret4;
                direct_page4 = dp_ret4;
            } else {
                bool x_flag3;
                uint8_t data_bank3;
                uint16_t direct_page3;
                if (value12 != 0xFFFF) {
                    uint16_t value14 = BUS16_RDP(c, (uint16_t)(dp_ret + 1));
                    BUS16_SET(c, (db_ret << 0x10) + 0x0A + x_ret, value14);
                    BUS16_SET(c, (db_ret << 0x10) + value14, value12);
                    x_flag3 = 0;
                    data_bank3 = db_ret;
                    direct_page3 = dp_ret;
                } else {
                    uint16_t value15 = BUS16_RDP(c, (uint16_t)(dp_ret + 1));
                    BUS16_SET(c, (db_ret << 0x10) + 0x0A + x_ret, value15);
                    r->a = value15;
                    r->y = value12;
                    r->c = value12 >= 0xFFFF;
                    r->z = value15 == 0;
                    r->n = value15 & 0x8000;
                    r->mf = 0;
                    r->sp -= 7;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xB2DD, 0x7EAC69); GUARD_JSR(c, sp_call, 0xB2DD); } /* wake_waiting_task */
                    r->sp += 7;
                    uint16_t dp_ret5 = r->dp;
                    uint8_t db_ret5 = r->db;
                    if (r->mf != 0) { c->fail = 3; return; }
                    bool x_ret8 = r->xf;
                    x_flag3 = x_ret8;
                    data_bank3 = db_ret5;
                    direct_page3 = dp_ret5;
                }
                x_flag4 = x_flag3;
                data_bank4 = data_bank3;
                direct_page4 = direct_page3;
            }
            x_flag5 = x_flag4;
            a2 = 0xFF;
            a_hi2 = 0xFF;
            data_bank5 = data_bank4;
            direct_page5 = direct_page4;
        }
        uint8_t value17 = RAM8(0x0000 + sp0 - 5);
        RAM8(0x0000 + sp0 - 3) = a2;
        uint8_t value20 = RAM8(0x0000 + sp0 - 2);
        uint8_t value21 = RAM8(0x0000 + sp0 - 1);
        uint8_t value22 = RAM8(0x0000 + sp0);
        r->mf = value20 & 0x20;
        r->xf = value20 & 0x10;
        r->db = value17;
        r->dp = (value22 << 8) | value21;
        r->i = value20 & 0x04;
        r->d = value20 & 0x08;
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0x7EB2AB, SOM_RTS, "gen", prepend_pending_record, 0, 0, 8, 1, 0, 80, 47)
