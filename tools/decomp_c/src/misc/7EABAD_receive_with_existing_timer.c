#include "som_c.h"

/* 7EABAD receive_with_existing_timer   [class B, 151 bytes, 76 instructions]
 * Source: src/boot/receive_with_existing_timer.s
 * Entry: M=8 bit X=16 bit DB=$7F D=$02EE.  Callers read: ABXYCZNV.
 */
static void receive_with_existing_timer(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x02EE) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a_hi = r->a >> 8;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 2;
    RAM8(0x0000 + sp0 - 1) = 0xEE;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7F;
    RAM8(0x0000 + sp0 - 4) = 0x7F;
    RAM8(0x0000 + sp0 - 4) = (((overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2) | carry;
    uint16_t value = RAM16(0x1009E);
    uint16_t value2 = BUS16(c, 0x7F000C + value);
    r->a = (a_hi << 8) | 0x7F;
    r->x = value2;
    r->y = value;
    r->z = value2 == 0;
    r->n = value2 & 0x8000;
    r->i = 1;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xABC2, 0x7ECC57); GUARD_JSR(c, sp_call, 0xABC2); } /* mark_timer_waiting */
    r->sp += 5;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xABC5, 0x7EA911); GUARD_JSR(c, sp_call, 0xABC5); } /* suspend_current_task */
    r->sp += 5;
    uint8_t db_ret2 = r->db;
    bool x_ret2 = r->xf;
    uint16_t x_ret3 = r->x;
    if (x_ret2) {
        RAM8(0x0000 + sp0 - 5) = (uint8_t)x_ret3;
        uint8_t value3 = BUS8_RDP(c, (db_ret2 << 0x10) + 0x9E);
        uint8_t value4 = BUS8_RDP(c, (db_ret2 << 0x10) + 0x0C + value3);
        r->x = value4;
        r->y = value3;
        r->z = value4 == 0;
        r->n = value4 & 0x80;
        r->xf = 1;
        r->sp -= 6;
        { const uint16_t sp_call = r->sp; JSR(c, 0xABCF, 0x7ECC43); GUARD_JSR(c, sp_call, 0xABCF); } /* mark_timer_ready */
        r->sp += 6;
        uint16_t dp_ret3 = r->dp;
        uint8_t db_ret3 = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        bool x_ret4 = r->xf;
        uint16_t a_all3 = r->a;
        if (x_ret4) {
            uint8_t value5 = RAM8(0x0000 + sp0 - 5);
            if (value5 == 0) {
                uint8_t value6 = RAM8(0x0000 + sp0 - 4);
                uint8_t value7 = RAM8(0x0000 + sp0 - 3);
                uint8_t value8 = RAM8(0x0000 + sp0 - 2);
                uint8_t value9 = RAM8(0x0000 + sp0 - 1);
                uint8_t value10 = RAM8(0x0000 + sp0);
                r->x = value5 & 0xFFFF - ((value6 >> 4) & 1) * 0xFF00;
                r->y = value3 & 0xFFFF - ((value6 >> 4) & 1) * 0xFF00;
                r->c = value8 & 0x01;
                r->z = ((value10 << 8) | value9) == 0;
                r->n = ((value10 << 8) | value9) & 0x8000;
                r->v = value8 & 0x40;
                r->mf = value8 & 0x20;
                r->xf = value8 & 0x10;
                r->db = value7;
                r->dp = (value10 << 8) | value9;
                r->i = value8 & 0x04;
                r->d = value8 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
            uint8_t value11 = BUS8_RDP(c, (db_ret3 << 0x10) + 2 + value5);
            bool m_flag;
            bool x_flag;
            uint8_t a1;
            uint8_t a_hi1;
            uint16_t x1;
            uint8_t data_bank;
            uint16_t direct_page;
            if (value11 != 0xFF) {
                m_flag = 1;
                x_flag = 1;
                a1 = value11;
                a_hi1 = a_all3 >> 8;
                x1 = value5;
                data_bank = db_ret3;
                direct_page = dp_ret3;
            } else {
                r->a = (a_all3 >> 8 << 8) | value11;
                r->x = value5;
                r->c = value11 >= 0xFF;
                r->z = value11 == 0xFF;
                r->n = (uint8_t)(value11 - 0xFF) & 0x80;
                r->xf = 1;
                r->sp -= 5;
                { const uint16_t sp_call = r->sp; JSR(c, 0xABDE, 0x7EB1DD); GUARD_JSR(c, sp_call, 0xABDE); } /* release_eight_byte_record */
                r->sp += 5;
                uint16_t dp_ret4 = r->dp;
                uint8_t db_ret4 = r->db;
                bool m_ret3 = r->mf;
                if (r->xf != 0) { c->fail = 3; return; }
                uint16_t a_all4 = r->a;
                m_flag = m_ret3;
                x_flag = 0;
                a1 = (uint8_t)a_all4;
                a_hi1 = a_all4 >> 8;
                x1 = 0;
                data_bank = db_ret4;
                direct_page = dp_ret4;
            }
            uint8_t value12 = RAM8(0x0000 + sp0 - 4);
            uint8_t value13 = RAM8(0x0000 + sp0 - 3);
            uint8_t value14 = RAM8(0x0000 + sp0 - 2);
            uint8_t value15 = RAM8(0x0000 + sp0 - 1);
            uint8_t value16 = RAM8(0x0000 + sp0);
            r->a = (a_hi1 << 8) | a1;
            r->x = x1 & 0xFFFF - ((value12 >> 4) & 1) * 0xFF00;
            r->y = value3 & 0xFFFF - ((value12 >> 4) & 1) * 0xFF00;
            r->c = value14 & 0x01;
            r->z = ((value16 << 8) | value15) == 0;
            r->n = ((value16 << 8) | value15) & 0x8000;
            r->v = value14 & 0x40;
            r->mf = value14 & 0x20;
            r->xf = value14 & 0x10;
            r->db = value13;
            r->dp = (value16 << 8) | value15;
            r->i = value14 & 0x04;
            r->d = value14 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        } else {
            c->fail = 3;
            return;
        }
    } else {
        RAM8(0x0000 + sp0 - 5) = x_ret3 >> 8;
        RAM8(0x0000 + sp0 - 6) = (uint8_t)x_ret3;
        uint16_t value22 = BUS16_RDP(c, (db_ret2 << 0x10) + 0x9E);
        uint16_t value23 = BUS16_RDP(c, (db_ret2 << 0x10) + 0x0C + value22);
        r->x = value23;
        r->y = value22;
        r->z = value23 == 0;
        r->n = value23 & 0x8000;
        r->xf = 0;
        r->sp -= 7;
        { const uint16_t sp_call = r->sp; JSR(c, 0xABCF, 0x7ECC43); GUARD_JSR(c, sp_call, 0xABCF); } /* mark_timer_ready */
        r->sp += 7;
        uint16_t dp_ret5 = r->dp;
        uint8_t db_ret5 = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        bool x_ret5 = r->xf;
        uint16_t a_all5 = r->a;
        if (x_ret5) {
            c->fail = 3;
            return;
        } else {
            uint8_t value30 = RAM8(0x0000 + sp0 - 6);
            uint8_t value31 = RAM8(0x0000 + sp0 - 5);
            if (((value31 << 8) | value30) == 0) {
                uint8_t value32 = RAM8(0x0000 + sp0 - 4);
                uint8_t value33 = RAM8(0x0000 + sp0 - 3);
                uint8_t value34 = RAM8(0x0000 + sp0 - 2);
                uint8_t value35 = RAM8(0x0000 + sp0 - 1);
                uint8_t value36 = RAM8(0x0000 + sp0);
                r->x = ((value31 << 8) | value30) & 0xFFFF - ((value32 >> 4) & 1) * 0xFF00;
                r->y = value22 & 0xFFFF - ((value32 >> 4) & 1) * 0xFF00;
                r->c = value34 & 0x01;
                r->z = ((value36 << 8) | value35) == 0;
                r->n = ((value36 << 8) | value35) & 0x8000;
                r->v = value34 & 0x40;
                r->mf = value34 & 0x20;
                r->xf = value34 & 0x10;
                r->db = value33;
                r->dp = (value36 << 8) | value35;
                r->i = value34 & 0x04;
                r->d = value34 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
            uint8_t value37 = BUS8_RDP(c, (db_ret5 << 0x10) + 2 + ((value31 << 8) | value30));
            bool m_flag2;
            uint8_t a2;
            uint8_t a_hi2;
            uint16_t x2;
            uint8_t data_bank2;
            uint16_t direct_page2;
            if (value37 != 0xFF) {
                m_flag2 = 1;
                a2 = value37;
                a_hi2 = a_all5 >> 8;
                x2 = (value31 << 8) | value30;
                data_bank2 = db_ret5;
                direct_page2 = dp_ret5;
            } else {
                r->a = (a_all5 >> 8 << 8) | value37;
                r->x = (value31 << 8) | value30;
                r->c = value37 >= 0xFF;
                r->z = value37 == 0xFF;
                r->n = (uint8_t)(value37 - 0xFF) & 0x80;
                r->xf = 0;
                r->sp -= 5;
                { const uint16_t sp_call = r->sp; JSR(c, 0xABDE, 0x7EB1DD); GUARD_JSR(c, sp_call, 0xABDE); } /* release_eight_byte_record */
                r->sp += 5;
                uint16_t dp_ret6 = r->dp;
                uint8_t db_ret6 = r->db;
                bool m_ret4 = r->mf;
                if (r->xf != 0) { c->fail = 3; return; }
                uint16_t a_all6 = r->a;
                m_flag2 = m_ret4;
                a2 = (uint8_t)a_all6;
                a_hi2 = a_all6 >> 8;
                x2 = 0;
                data_bank2 = db_ret6;
                direct_page2 = dp_ret6;
            }
            uint8_t value38 = RAM8(0x0000 + sp0 - 4);
            uint8_t value39 = RAM8(0x0000 + sp0 - 3);
            uint8_t value40 = RAM8(0x0000 + sp0 - 2);
            uint8_t value41 = RAM8(0x0000 + sp0 - 1);
            uint8_t value42 = RAM8(0x0000 + sp0);
            r->a = (a_hi2 << 8) | a2;
            r->x = x2 & 0xFFFF - ((value38 >> 4) & 1) * 0xFF00;
            r->y = value22 & 0xFFFF - ((value38 >> 4) & 1) * 0xFF00;
            r->c = value40 & 0x01;
            r->z = ((value42 << 8) | value41) == 0;
            r->n = ((value42 << 8) | value41) & 0x8000;
            r->v = value40 & 0x40;
            r->mf = value40 & 0x20;
            r->xf = value40 & 0x10;
            r->db = value39;
            r->dp = (value42 << 8) | value41;
            r->i = value40 & 0x04;
            r->d = value40 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
    }
}
SOM_REGISTER(0x7EABAD, SOM_RTS, "gen", receive_with_existing_timer, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 7, 1, 0, 151, 76)
