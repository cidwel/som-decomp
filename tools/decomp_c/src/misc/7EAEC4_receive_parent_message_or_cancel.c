#include "som_c.h"

/* 7EAEC4 receive_parent_message_or_cancel   [class B, 71 bytes, 35 instructions]
 * Source: src/boot/receive_parent_message_or_cancel.s
 * Entry: M=8 bit X=16 bit DB=$7F D=$02EE.  Callers read: ABXYV.
 */
static void receive_parent_message_or_cancel(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x02EE) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 2;
    RAM8(0x0000 + sp0 - 1) = 0xEE;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7F;
    RAM8(0x0000 + sp0 - 4) = 0x7F;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = x;
    uint16_t y1 = y;
    bool carry1 = carry;
    bool zero1 = 0;
    bool negative1 = 0;
    bool overflow1 = overflow;
    uint8_t data_bank = 0x7F;
    uint16_t direct_page = 0x02EE;
    for (;;) {
        r->x = x1;
        r->y = y1;
        r->c = carry1;
        r->z = zero1;
        r->n = negative1;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank;
        r->dp = direct_page;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0xAED1, 0x7EAE37); GUARD_JSR(c, sp_call, 0xAED1); } /* enter_native_pause_gate_and_test_live_pause_bit */
        r->sp += 4;
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t x_ret = r->x;
        if (x_ret == 0) {
            r->c = x_ret >= 0;
            r->z = x_ret == 0;
            r->n = x_ret & 0x8000;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR(c, 0xAEDE, 0x7EABAD); GUARD_JSR(c, sp_call, 0xAEDE); } /* receive_with_existing_timer */
            r->sp += 4;
            uint8_t db_ret2 = r->db;
            if (r->mf != 1) { c->fail = 3; return; }
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t a_all2 = r->a;
            uint16_t x_ret2 = r->x;
            uint16_t y_ret2 = r->y;
            if (x_ret2 == 0) {
                uint8_t value = RAM8(0x0000 + sp0 - 3);
                uint8_t value2 = RAM8(0x0000 + sp0 - 2);
                uint8_t value3 = RAM8(0x0000 + sp0 - 1);
                uint8_t value4 = RAM8(0x0000 + sp0);
                r->a = (a_all2 >> 8 << 8) | 1;
                r->v = value2 & 0x40;
                r->mf = value2 & 0x20;
                r->xf = value2 & 0x10;
                r->db = value;
                r->dp = (value4 << 8) | value3;
                r->i = value2 & 0x04;
                r->d = value2 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
            uint8_t value5 = BUS8_RDP(c, (db_ret2 << 0x10) + 2 + x_ret2);
            if ((uint8_t)(value5 - 0xFE) != 0) {
                uint8_t value6 = RAM8(0x0000 + sp0 - 3);
                uint8_t value7 = RAM8(0x0000 + sp0 - 2);
                uint8_t value8 = RAM8(0x0000 + sp0 - 1);
                uint8_t value9 = RAM8(0x0000 + sp0);
                r->a = (a_all2 >> 8 << 8) | (uint8_t)(value5 - 0xFE);
                r->v = value7 & 0x40;
                r->mf = value7 & 0x20;
                r->xf = value7 & 0x10;
                r->db = value6;
                r->dp = (value9 << 8) | value8;
                r->i = value7 & 0x04;
                r->d = value7 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
            uint8_t value10 = BUS8_RDP(c, (db_ret2 << 0x10) + 4 + x_ret2);
            if (value10 == 1) {
                r->a = (a_all2 >> 8 << 8) | value10;
                r->c = value10 >= 1;
                r->z = value10 == 1;
                r->n = (uint8_t)(value10 - 1) & 0x80;
                r->v = ((value5 ^ 0xFE) & (value5 ^ (uint8_t)(value5 - 0xFE)) & 0x80) != 0;
                r->sp -= 4;
                { const uint16_t sp_call = r->sp; JSR(c, 0xAEFD, 0x7EB1DD); GUARD_JSR(c, sp_call, 0xAEFD); } /* release_eight_byte_record */
                r->sp += 4;
                if (r->mf != 1) { c->fail = 3; return; }
                if (r->xf != 0) { c->fail = 3; return; }
                uint16_t a_all3 = r->a;
                uint8_t value11 = RAM8(0x0000 + sp0 - 3);
                uint8_t value12 = RAM8(0x0000 + sp0 - 2);
                uint8_t value13 = RAM8(0x0000 + sp0 - 1);
                uint8_t value14 = RAM8(0x0000 + sp0);
                r->a = (a_all3 >> 8 << 8) | 0;
                r->x = 0;
                r->v = value12 & 0x40;
                r->mf = value12 & 0x20;
                r->xf = value12 & 0x10;
                r->db = value11;
                r->dp = (value14 << 8) | value13;
                r->i = value12 & 0x04;
                r->d = value12 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
            r->a = (a_all2 >> 8 << 8) | value10;
            r->c = value10 >= 1;
            r->z = value10 == 1;
            r->n = (uint8_t)(value10 - 1) & 0x80;
            r->v = ((value5 ^ 0xFE) & (value5 ^ (uint8_t)(value5 - 0xFE)) & 0x80) != 0;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR(c, 0xAEF5, 0x7EB1DD); GUARD_JSR(c, sp_call, 0xAEF5); } /* release_eight_byte_record */
            r->sp += 4;
            uint16_t dp_ret4 = r->dp;
            uint8_t db_ret4 = r->db;
            bool m_ret2 = r->mf;
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t a_all4 = r->a;
            bool carry_ret4 = r->c;
            bool overflow_ret4 = r->v;
            if (m_ret2 != 1) { c->fail = 3; return; }
            a_hi1 = a_all4 >> 8;
            x1 = 0;
            y1 = y_ret2;
            carry1 = carry_ret4;
            zero1 = 1;
            negative1 = 0;
            overflow1 = overflow_ret4;
            data_bank = db_ret4;
            direct_page = dp_ret4;
            continue;
        }
        r->c = x_ret >= 0;
        r->z = x_ret == 0;
        r->n = x_ret & 0x8000;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0xAED9, 0x7EABE7); GUARD_JSR(c, sp_call, 0xAED9); } /* receive_with_supplied_delay */
        r->sp += 4;
        uint8_t db_ret5 = r->db;
        bool m_ret3 = r->mf;
        bool x_ret3 = r->xf;
        uint16_t a_all5 = r->a;
        uint16_t x_ret4 = r->x;
        uint16_t y_ret3 = r->y;
        if (x_ret3) {
            c->fail = 3; /* operand size does not fit the register width on this path */
            return;
        } else {
            if (x_ret4 == 0) {
                if (m_ret3) {
                    uint8_t value15 = RAM8(0x0000 + sp0 - 3);
                    uint8_t value16 = RAM8(0x0000 + sp0 - 2);
                    uint8_t value17 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value18 = RAM8(0x0000 + sp0);
                    r->a = (a_all5 >> 8 << 8) | 1;
                    r->v = value16 & 0x40;
                    r->mf = value16 & 0x20;
                    r->xf = value16 & 0x10;
                    r->db = value15;
                    r->dp = (value18 << 8) | value17;
                    r->i = value16 & 0x04;
                    r->d = value16 & 0x08;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                } else {
                    c->fail = 3; /* operand size does not fit the register width on this path */
                    return;
                }
            }
            if (m_ret3) {
                uint8_t value19 = BUS8_RDP(c, (db_ret5 << 0x10) + 2 + x_ret4);
                if ((uint8_t)(value19 - 0xFE) != 0) {
                    uint8_t value20 = RAM8(0x0000 + sp0 - 3);
                    uint8_t value21 = RAM8(0x0000 + sp0 - 2);
                    uint8_t value22 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value23 = RAM8(0x0000 + sp0);
                    r->a = (a_all5 >> 8 << 8) | (uint8_t)(value19 - 0xFE);
                    r->v = value21 & 0x40;
                    r->mf = value21 & 0x20;
                    r->xf = value21 & 0x10;
                    r->db = value20;
                    r->dp = (value23 << 8) | value22;
                    r->i = value21 & 0x04;
                    r->d = value21 & 0x08;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
                uint8_t value24 = BUS8_RDP(c, (db_ret5 << 0x10) + 4 + x_ret4);
                if (value24 == 1) {
                    r->a = (a_all5 >> 8 << 8) | value24;
                    r->c = value24 >= 1;
                    r->z = value24 == 1;
                    r->n = (uint8_t)(value24 - 1) & 0x80;
                    r->v = ((value19 ^ 0xFE) & (value19 ^ (uint8_t)(value19 - 0xFE)) & 0x80) != 0;
                    r->mf = 1;
                    r->xf = 0;
                    r->sp -= 4;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xAEFD, 0x7EB1DD); GUARD_JSR(c, sp_call, 0xAEFD); } /* release_eight_byte_record */
                    r->sp += 4;
                    if (r->mf != 1) { c->fail = 3; return; }
                    if (r->xf != 0) { c->fail = 3; return; }
                    uint16_t a_all6 = r->a;
                    uint8_t value25 = RAM8(0x0000 + sp0 - 3);
                    uint8_t value26 = RAM8(0x0000 + sp0 - 2);
                    uint8_t value27 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value28 = RAM8(0x0000 + sp0);
                    r->a = (a_all6 >> 8 << 8) | 0;
                    r->x = 0;
                    r->v = value26 & 0x40;
                    r->mf = value26 & 0x20;
                    r->xf = value26 & 0x10;
                    r->db = value25;
                    r->dp = (value28 << 8) | value27;
                    r->i = value26 & 0x04;
                    r->d = value26 & 0x08;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
                r->a = (a_all5 >> 8 << 8) | value24;
                r->c = value24 >= 1;
                r->z = value24 == 1;
                r->n = (uint8_t)(value24 - 1) & 0x80;
                r->v = ((value19 ^ 0xFE) & (value19 ^ (uint8_t)(value19 - 0xFE)) & 0x80) != 0;
                r->mf = 1;
                r->xf = 0;
                r->sp -= 4;
                { const uint16_t sp_call = r->sp; JSR(c, 0xAEF5, 0x7EB1DD); GUARD_JSR(c, sp_call, 0xAEF5); } /* release_eight_byte_record */
                r->sp += 4;
                uint16_t dp_ret7 = r->dp;
                uint8_t db_ret7 = r->db;
                bool m_ret4 = r->mf;
                if (r->xf != 0) { c->fail = 3; return; }
                uint16_t a_all7 = r->a;
                bool carry_ret7 = r->c;
                bool overflow_ret7 = r->v;
                if (m_ret4 != 1) { c->fail = 3; return; }
                a_hi1 = a_all7 >> 8;
                x1 = 0;
                y1 = y_ret3;
                carry1 = carry_ret7;
                zero1 = 1;
                negative1 = 0;
                overflow1 = overflow_ret7;
                data_bank = db_ret7;
                direct_page = dp_ret7;
                continue;
            } else {
                uint16_t value29 = BUS16_RDP(c, (db_ret5 << 0x10) + 2 + x_ret4);
                c->fail = 3; /* operand size does not fit the register width on this path */
                return;
            }
        }
    }
}
SOM_REGISTER(0x7EAEC4, SOM_RTS, "gen", receive_parent_message_or_cancel, 0, L_A | L_B | L_X | L_Y | L_V, 5, 1, 0, 71, 35)
