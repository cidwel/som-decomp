#include "som_c.h"

/* 7ED17F dispatch_parent_messages   [class B, 91 bytes, 40 instructions]
 * Source: src/boot/dispatch_parent_messages.s
 * Documented in docs/boot.md
 * Entry: M=8 bit X=16 bit DB=$7F D=$02EE.  Callers read: ABXYCV.
 */
static void dispatch_parent_messages(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x02EE) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a = r->a & 0xFF;
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
    uint8_t a1 = a;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = x;
    uint16_t y1 = y;
    bool carry1 = carry;
    bool zero1 = zero;
    bool negative1 = negative;
    bool overflow1 = overflow;
    uint8_t data_bank = 0x7F;
    uint16_t direct_page = 0x02EE;
    for (;;) {
        r->a = (a_hi1 << 8) | a1;
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
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD18C, 0x7EAEC4); GUARD_JSR(c, sp_call, 0xD18C); } /* receive_parent_message_or_cancel */
        r->sp += 3;
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        uint16_t a_all = r->a;
        uint16_t x_ret = r->x;
        uint16_t y_ret = r->y;
        uint8_t a4;
        uint8_t a_hi4;
        uint16_t x4;
        uint16_t y4;
        uint8_t data_bank4;
        uint16_t direct_page4;
        if (x_ret == 0) {
            uint8_t a2;
            uint8_t a_hi2;
            uint16_t x2;
            uint16_t y2;
            uint8_t data_bank2;
            uint16_t direct_page2;
            if ((uint8_t)a_all != 0) {
                a2 = (uint8_t)a_all;
                a_hi2 = a_all >> 8;
                x2 = x_ret;
                y2 = y_ret;
                data_bank2 = db_ret;
                direct_page2 = dp_ret;
            } else {
                r->c = (uint8_t)a_all >= 0;
                r->z = (uint8_t)a_all == 0;
                r->n = (uint8_t)a_all & 0x80;
                r->sp -= 3;
                { const uint16_t sp_call = r->sp; JSR(c, 0xD1D1, 0x7ED14C); GUARD_JSR(c, sp_call, 0xD1D1); } /* ensure_parent_control_task */
                r->sp += 3;
                uint16_t dp_ret2 = r->dp;
                uint8_t db_ret2 = r->db;
                if (r->mf != 1) { c->fail = 3; return; }
                if (r->xf != 0) { c->fail = 3; return; }
                uint16_t a_all2 = r->a;
                uint16_t x_ret2 = r->x;
                uint16_t y_ret2 = r->y;
                bool carry_ret2 = r->c;
                bool overflow_ret2 = r->v;
                uint8_t value = BUS8_RDP(c, (db_ret2 << 0x10) + 0x0314);
                if (value != 0) {
                    a1 = value;
                    a_hi1 = a_all2 >> 8;
                    x1 = 0;
                    y1 = y_ret2;
                    carry1 = carry_ret2;
                    zero1 = 1;
                    negative1 = 0;
                    overflow1 = overflow_ret2;
                    data_bank = db_ret2;
                    direct_page = dp_ret2;
                    continue;
                }
                a2 = value;
                a_hi2 = a_all2 >> 8;
                x2 = x_ret2;
                y2 = y_ret2;
                data_bank2 = db_ret2;
                direct_page2 = dp_ret2;
            }
            a4 = a2;
            a_hi4 = a_hi2;
            x4 = x2;
            y4 = y2;
            data_bank4 = data_bank2;
            direct_page4 = direct_page2;
        } else {
            uint8_t value2 = BUS8_RDP(c, (db_ret << 0x10) + 2 + x_ret);
            uint8_t value3 = BUS8_RDP(c, (db_ret << 0x10) + 0x0312);
            if (value2 == value3) {
                r->a = (a_all >> 8 << 8) | value2;
                r->c = value2 >= value3;
                r->z = value2 == value3;
                r->n = (uint8_t)(value2 - value3) & 0x80;
                r->sp -= 3;
                { const uint16_t sp_call = r->sp; JSR(c, 0xD1BC, 0x7ED081); GUARD_JSR(c, sp_call, 0xD1BC); } /* handle_parent_buffer_message */
                r->sp += 3;
                uint16_t dp_ret3 = r->dp;
                uint8_t db_ret3 = r->db;
                bool m_ret = r->mf;
                if (r->xf != 0) { c->fail = 3; return; }
                uint16_t a_all3 = r->a;
                uint16_t y_ret3 = r->y;
                bool carry_ret3 = r->c;
                bool overflow_ret3 = r->v;
                if (m_ret != 1) { c->fail = 3; return; }
                a1 = (uint8_t)a_all3;
                a_hi1 = a_all3 >> 8;
                x1 = 0;
                y1 = y_ret3;
                carry1 = carry_ret3;
                zero1 = 1;
                negative1 = 0;
                overflow1 = overflow_ret3;
                data_bank = db_ret3;
                direct_page = dp_ret3;
                continue;
            }
            uint8_t value4 = BUS8_RDP(c, (db_ret << 0x10) + 0x0314);
            uint8_t a3;
            uint8_t a_hi3;
            uint16_t x3;
            uint16_t y3;
            uint8_t data_bank3;
            uint16_t direct_page3;
            if (value2 == value4) {
                BUS8_SET(c, (db_ret << 0x10) + 0x0314, 0);
                a3 = 0;
                a_hi3 = a_all >> 8;
                x3 = x_ret;
                y3 = y_ret;
                data_bank3 = db_ret;
                direct_page3 = dp_ret;
            } else {
                uint8_t value5 = BUS8_RDP(c, (db_ret << 0x10) + 0x0315);
                if (value2 == value5) {
                    r->a = (a_all >> 8 << 8) | value2;
                    r->c = value2 >= value5;
                    r->z = value2 == value5;
                    r->n = (uint8_t)(value2 - value5) & 0x80;
                    r->sp -= 3;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xD1C8, 0x7ED0AE); GUARD_JSR(c, sp_call, 0xD1C8); } /* handle_input_task_completion */
                    r->sp += 3;
                    uint16_t dp_ret4 = r->dp;
                    uint8_t db_ret4 = r->db;
                    bool m_ret2 = r->mf;
                    if (r->xf != 0) { c->fail = 3; return; }
                    uint16_t a_all4 = r->a;
                    uint16_t y_ret4 = r->y;
                    bool carry_ret4 = r->c;
                    bool overflow_ret4 = r->v;
                    if (m_ret2 != 1) { c->fail = 3; return; }
                    a1 = (uint8_t)a_all4;
                    a_hi1 = a_all4 >> 8;
                    x1 = 0;
                    y1 = y_ret4;
                    carry1 = carry_ret4;
                    zero1 = 1;
                    negative1 = 0;
                    overflow1 = overflow_ret4;
                    data_bank = db_ret4;
                    direct_page = dp_ret4;
                    continue;
                }
                uint8_t value6 = BUS8_RDP(c, (db_ret << 0x10) + 0x0311);
                if (value2 != value6) {
                    r->c = value2 >= value6;
                    r->z = value2 == value6;
                    r->n = (uint8_t)(value2 - value6) & 0x80;
                    r->sp -= 3;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xD1AB, 0x7ED023); GUARD_JSR(c, sp_call, 0xD1AB); } /* handle_parent_tracked_task_message */
                    r->sp += 3;
                    uint16_t dp_ret6 = r->dp;
                    uint8_t db_ret6 = r->db;
                    bool m_ret3 = r->mf;
                    if (r->xf != 0) { c->fail = 3; return; }
                    uint16_t a_all6 = r->a;
                    bool carry_ret6 = r->c;
                    bool overflow_ret6 = r->v;
                    if (m_ret3 != 1) { c->fail = 3; return; }
                    a1 = (uint8_t)a_all6;
                    a_hi1 = a_all6 >> 8;
                    x1 = 0;
                    y1 = y_ret;
                    carry1 = carry_ret6;
                    zero1 = 1;
                    negative1 = 0;
                    overflow1 = overflow_ret6;
                    data_bank = db_ret6;
                    direct_page = dp_ret6;
                    continue;
                }
                r->c = value2 >= value6;
                r->z = value2 == value6;
                r->n = (uint8_t)(value2 - value6) & 0x80;
                r->sp -= 3;
                { const uint16_t sp_call = r->sp; JSR(c, 0xD1B0, 0x7ECFE2); GUARD_JSR(c, sp_call, 0xD1B0); } /* handle_parent_image_message */
                r->sp += 3;
                uint16_t dp_ret5 = r->dp;
                uint8_t db_ret5 = r->db;
                uint16_t a_all5 = r->a;
                uint16_t y_ret5 = r->y;
                bool overflow_ret5 = r->v;
                if ((uint8_t)a_all5 == 0) {
                    a1 = (uint8_t)a_all5;
                    a_hi1 = a_all5 >> 8;
                    x1 = 0;
                    y1 = y_ret5;
                    carry1 = (uint8_t)a_all5 >= 0;
                    zero1 = 1;
                    negative1 = 0;
                    overflow1 = overflow_ret5;
                    data_bank = db_ret5;
                    direct_page = dp_ret5;
                    continue;
                }
                a3 = (uint8_t)a_all5;
                a_hi3 = a_all5 >> 8;
                x3 = 0;
                y3 = y_ret5;
                data_bank3 = db_ret5;
                direct_page3 = dp_ret5;
            }
            a4 = a3;
            a_hi4 = a_hi3;
            x4 = x3;
            y4 = y3;
            data_bank4 = data_bank3;
            direct_page4 = direct_page3;
        }
        a1 = a4;
        a_hi1 = a_hi4;
        x1 = x4;
        y1 = y4;
        data_bank = data_bank4;
        direct_page = direct_page4;
        break;
    }
    uint8_t value7 = RAM8(0x0000 + sp0 - 2);
    uint8_t value8 = RAM8(0x0000 + sp0 - 1);
    uint8_t value9 = RAM8(0x0000 + sp0);
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = value7 & 0x01;
    r->v = value7 & 0x40;
    r->mf = value7 & 0x20;
    r->xf = value7 & 0x10;
    r->db = data_bank;
    r->dp = (value9 << 8) | value8;
    r->i = value7 & 0x04;
    r->d = value7 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7ED17F, SOM_RTS, "gen", dispatch_parent_messages, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 3, 1, 0, 91, 40)
