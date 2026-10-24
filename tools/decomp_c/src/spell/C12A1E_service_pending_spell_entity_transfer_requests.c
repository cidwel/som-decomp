#include "som_c.h"

/* C12A1E service_pending_spell_entity_transfer_requests   [class B, 47 bytes, 26 instructions]
 * Source: src/rom/service_pending_spell_entity_transfer_requests.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$01B4.  Callers read: BXYCZNV.
 */
static void service_pending_spell_entity_transfer_requests(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x01B4) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 1;
    RAM8(0x0000 + sp0 - 1) = 0xB4;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7E;
    RAM8(0x0000 + sp0 - 4) = 0x7E;
    RAM8(0x0000 + sp0 - 4) = (((overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2) | carry;
    uint16_t value = RAM16(0x8212);
    bool m_flag3;
    bool x_flag3;
    uint8_t a_hi3;
    uint16_t x3;
    uint16_t y3;
    uint8_t data_bank3;
    if (value == 0) {
        m_flag3 = 1;
        x_flag3 = 0;
        a_hi3 = a_hi;
        x3 = value;
        y3 = y;
        data_bank3 = 0x7E;
    } else {
        uint8_t value2 = RAM8(0x821A);
        bool m_flag2;
        bool x_flag2;
        uint8_t a_hi2;
        uint16_t x2;
        uint16_t y2;
        uint8_t data_bank2;
        if (value2 == 0) {
            m_flag2 = 1;
            x_flag2 = 0;
            a_hi2 = a_hi;
            x2 = value;
            y2 = y;
            data_bank2 = 0x7E;
        } else {
            uint8_t value3 = RAM8(0x8210);
            bool m_flag;
            bool x_flag;
            uint8_t a_hi1;
            uint16_t x1;
            uint16_t y1;
            uint8_t data_bank;
            if (value3 != 0) {
                r->a = (a_hi << 8) | value3;
                r->x = value;
                r->z = value3 == 0;
                r->n = value3 & 0x80;
                r->i = 1;
                r->sp -= 5;
                { const uint16_t sp_call = r->sp; JSR(c, 0x2A41, 0xC12A5C); GUARD_JSR(c, sp_call, 0x2A41); } /* flush_pending_spell_entity_transfers_synchronously */
                r->sp += 5;
                uint8_t db_ret = r->db;
                bool m_ret = r->mf;
                bool x_ret = r->xf;
                uint16_t a_all = r->a;
                uint16_t x_ret2 = r->x;
                uint16_t y_ret = r->y;
                m_flag = m_ret;
                x_flag = x_ret;
                a_hi1 = a_all >> 8;
                x1 = x_ret2;
                y1 = y_ret;
                data_bank = db_ret;
            } else {
                r->a = (a_hi << 8) | value3;
                r->x = value;
                r->z = value3 == 0;
                r->n = value3 & 0x80;
                r->i = 1;
                r->sp -= 5;
                { const uint16_t sp_call = r->sp; JSR(c, 0x2A3C, 0xC12A4D); GUARD_JSR(c, sp_call, 0x2A3C); } /* snapshot_spell_entity_pending_transfer_count */
                r->sp += 5;
                uint16_t a_all2 = r->a;
                m_flag = 1;
                x_flag = 0;
                a_hi1 = a_all2 >> 8;
                x1 = value;
                y1 = y;
                data_bank = 0x7E;
            }
            m_flag2 = m_flag;
            x_flag2 = x_flag;
            a_hi2 = a_hi1;
            x2 = x1;
            y2 = y1;
            data_bank2 = data_bank;
        }
        m_flag3 = m_flag2;
        x_flag3 = x_flag2;
        a_hi3 = a_hi2;
        x3 = x2;
        y3 = y2;
        data_bank3 = data_bank2;
    }
    if (m_flag3) {
        uint8_t value4 = BUS8_RDP(c, (data_bank3 << 0x10) + 0x8230);
        BUS8_SET(c, (data_bank3 << 0x10) + 0x8230, (uint8_t)(value4 + 1));
        uint8_t value5 = RAM8(0x0000 + sp0 - 4);
        if (value5 & 0x20) {
            uint8_t value6 = BUS8_RDP(c, (data_bank3 << 0x10) + 0x8230);
            BUS8_SET(c, (data_bank3 << 0x10) + 0x8230, (uint8_t)(value6 - 1));
            uint8_t value7 = RAM8(0x0000 + sp0 - 3);
            uint8_t value8 = RAM8(0x0000 + sp0 - 2);
            uint8_t value9 = RAM8(0x0000 + sp0 - 1);
            uint8_t value10 = RAM8(0x0000 + sp0);
            r->a = (a_hi3 << 8) | a;
            r->x = x3 & 0xFFFF - ((value5 >> 4) & 1) * 0xFF00;
            r->y = y3 & 0xFFFF - ((value5 >> 4) & 1) * 0xFF00;
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
        } else {
            uint16_t value11 = BUS16_RDP(c, (data_bank3 << 0x10) + 0x8230);
            BUS16_RMW_SET(c, (data_bank3 << 0x10) + 0x8230, (uint16_t)(value11 - 1));
            uint8_t value12 = RAM8(0x0000 + sp0 - 3);
            uint8_t value13 = RAM8(0x0000 + sp0 - 2);
            uint8_t value14 = RAM8(0x0000 + sp0 - 1);
            uint8_t value15 = RAM8(0x0000 + sp0);
            r->a = (a_hi3 << 8) | a;
            r->x = x3 & 0xFFFF - ((value5 >> 4) & 1) * 0xFF00;
            r->y = y3 & 0xFFFF - ((value5 >> 4) & 1) * 0xFF00;
            r->c = value13 & 0x01;
            r->z = ((value15 << 8) | value14) == 0;
            r->n = ((value15 << 8) | value14) & 0x8000;
            r->v = value13 & 0x40;
            r->mf = value13 & 0x20;
            r->xf = value13 & 0x10;
            r->db = value12;
            r->dp = (value15 << 8) | value14;
            r->i = value13 & 0x04;
            r->d = value13 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
    } else {
        uint16_t value16 = BUS16_RDP(c, (data_bank3 << 0x10) + 0x8230);
        BUS16_RMW_SET(c, (data_bank3 << 0x10) + 0x8230, (uint16_t)(value16 + 1));
        uint8_t value17 = RAM8(0x0000 + sp0 - 4);
        if (value17 & 0x20) {
            uint8_t value18 = BUS8_RDP(c, (data_bank3 << 0x10) + 0x8230);
            BUS8_SET(c, (data_bank3 << 0x10) + 0x8230, (uint8_t)(value18 - 1));
            uint8_t value19 = RAM8(0x0000 + sp0 - 3);
            uint8_t value20 = RAM8(0x0000 + sp0 - 2);
            uint8_t value21 = RAM8(0x0000 + sp0 - 1);
            uint8_t value22 = RAM8(0x0000 + sp0);
            r->a = (a_hi3 << 8) | a;
            r->x = x3 & 0xFFFF - ((value17 >> 4) & 1) * 0xFF00;
            r->y = y3 & 0xFFFF - ((value17 >> 4) & 1) * 0xFF00;
            r->c = value20 & 0x01;
            r->z = ((value22 << 8) | value21) == 0;
            r->n = ((value22 << 8) | value21) & 0x8000;
            r->v = value20 & 0x40;
            r->mf = value20 & 0x20;
            r->xf = value20 & 0x10;
            r->db = value19;
            r->dp = (value22 << 8) | value21;
            r->i = value20 & 0x04;
            r->d = value20 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        } else {
            uint16_t value23 = BUS16_RDP(c, (data_bank3 << 0x10) + 0x8230);
            BUS16_RMW_SET(c, (data_bank3 << 0x10) + 0x8230, (uint16_t)(value23 - 1));
            uint8_t value24 = RAM8(0x0000 + sp0 - 3);
            uint8_t value25 = RAM8(0x0000 + sp0 - 2);
            uint8_t value26 = RAM8(0x0000 + sp0 - 1);
            uint8_t value27 = RAM8(0x0000 + sp0);
            r->a = (a_hi3 << 8) | a;
            r->x = x3 & 0xFFFF - ((value17 >> 4) & 1) * 0xFF00;
            r->y = y3 & 0xFFFF - ((value17 >> 4) & 1) * 0xFF00;
            r->c = value25 & 0x01;
            r->z = ((value27 << 8) | value26) == 0;
            r->n = ((value27 << 8) | value26) & 0x8000;
            r->v = value25 & 0x40;
            r->mf = value25 & 0x20;
            r->xf = value25 & 0x10;
            r->db = value24;
            r->dp = (value27 << 8) | value26;
            r->i = value25 & 0x04;
            r->d = value25 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
    }
}
SOM_REGISTER(0xC12A1E, SOM_RTS, "gen", service_pending_spell_entity_transfer_requests, 0, L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 5, 1, 0, 47, 26)
