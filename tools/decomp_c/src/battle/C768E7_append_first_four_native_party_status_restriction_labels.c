#include "som_c.h"

/* C768E7 append_first_four_native_party_status_restriction_labels   [class B, 76 bytes, 39 instructions]
 * Source: src/rom/append_first_four_native_party_status_restriction_labels.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void append_first_four_native_party_status_restriction_labels(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const bool overflow = r->v;
    RAM16_SET(0xA167, (a_hi << 8) | a);
    RAM16_SET(0xA169, 0);
    uint8_t a1 = 0x10;
    uint8_t a_hi1 = 0;
    uint16_t x1 = x;
    uint16_t y1 = 0;
    bool overflow1 = overflow;
    uint8_t data_bank = 0x7E;
    uint16_t direct_page = 0;
    for (;;) {
        RAM8(0x0000 + sp0) = a_hi1;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)((a_hi1 << 8) | a1);
        uint16_t value = BUS16_RDP(c, (data_bank << 0x10) + 0xA167);
        BUS16_RMW_SET(c, (data_bank << 0x10) + 0xA167, (uint16_t)(value << 1));
        if (!(value & 0x8000)) {
            uint16_t value2 = BUS16_RDP(c, (data_bank << 0x10) + 0xA169);
            if (value2 == 4) {
                r->a = (RAM8(0x0000 + sp0) << 8) | RAM8(0x0000 + sp0 - 1);
                r->x = x1;
                r->y = y1;
                r->c = value2 >= 4;
                r->v = overflow1;
                r->mf = 1;
                r->xf = 0;
                r->db = data_bank;
                r->dp = direct_page;
                RETURN_RTS(c);
            }
            uint8_t value5 = RAM8(0x0000 + sp0 - 1);
            uint8_t value6 = RAM8(0x0000 + sp0);
            if ((uint16_t)(((value6 << 8) | value5) - 1) != 0) {
                a1 = (uint8_t)(((value6 << 8) | value5) - 1);
                a_hi1 = (uint16_t)(((value6 << 8) | value5) - 1) >> 8;
                y1 = (uint16_t)(y1 + 1);
                continue;
            }
            uint16_t value7 = BUS16_RDP(c, (data_bank << 0x10) + 0xA169);
            uint8_t a2 = (uint8_t)(((value6 << 8) | value5) - 1);
            uint8_t a_hi2 = (uint16_t)(((value6 << 8) | value5) - 1) >> 8;
            uint16_t x2 = x1;
            uint16_t y2 = value7;
            bool carry1 = value2 >= 4;
            bool overflow2 = overflow1;
            uint8_t data_bank2 = data_bank;
            uint16_t direct_page2 = direct_page;
            for (;;) {
                r->a = (a_hi2 << 8) | a2;
                r->x = x2;
                r->y = y2;
                r->c = carry1;
                r->v = overflow2;
                r->mf = 1;
                r->xf = 0;
                r->db = data_bank2;
                r->dp = direct_page2;
                { const uint16_t sp_call = r->sp; JSR(c, 0x6925, 0xC7538D); GUARD_JSR(c, sp_call, 0x6925); } /* append_native_saved_slot_text_line_token */
                uint16_t dp_ret = r->dp;
                uint8_t db_ret = r->db;
                bool x_ret = r->xf;
                uint16_t a_all = r->a;
                uint16_t x_ret2 = r->x;
                if (x_ret) {
                    c->fail = 3; /* operand size does not fit the register width on this path */
                    return;
                } else {
                    uint8_t a2_next = (uint8_t)a_all;
                    uint8_t a_hi2_next = a_all >> 8;
                    uint16_t x2_next = x_ret2;
                    uint16_t y2_next = (uint16_t)(y2 + 1);
                    bool carry1_next = (uint16_t)(y2 + 1) >= 4;
                    uint8_t data_bank2_next = db_ret;
                    uint16_t direct_page2_next = dp_ret;
                    a2 = a2_next;
                    a_hi2 = a_hi2_next;
                    x2 = x2_next;
                    y2 = y2_next;
                    carry1 = carry1_next;
                    data_bank2 = data_bank2_next;
                    direct_page2 = direct_page2_next;
                }
                if (!(y2 != 4)) break;
            }
            r->a = (a_hi2 << 8) | a2;
            r->x = x2;
            r->y = y2;
            r->c = carry1;
            r->v = overflow2;
            r->mf = 1;
            r->xf = 0;
            r->db = data_bank2;
            r->dp = direct_page2;
            RETURN_RTS(c);
        }
        RAM8(0x0000 + sp0 - 2) = y1 >> 8;
        RAM8(0x0000 + sp0 - 3) = (uint8_t)y1;
        RAM8(0x0000 + sp0 - 4) = x1 >> 8;
        RAM8(0x0000 + sp0 - 5) = (uint8_t)x1;
        uint16_t value8 = BUS16(c, 0xC033D0 + (uint16_t)(y1 << 1));
        r->a = value8;
        r->x = x1;
        r->y = value8;
        r->c = y1 & 0x8000;
        r->z = x1 == 0;
        r->n = x1 & 0x8000;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank;
        r->dp = direct_page;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0x690A, 0xC76ABE); GUARD_JSR(c, sp_call, 0x690A); } /* select_bank_C7_and_copy_native_terminated_tokens */
        r->sp += 4;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0x690D, 0xC7538D); GUARD_JSR(c, sp_call, 0x690D); } /* append_native_saved_slot_text_line_token */
        r->sp += 4;
        uint16_t dp_ret3 = r->dp;
        uint8_t db_ret3 = r->db;
        bool x_ret5 = r->xf;
        uint16_t x_ret6 = r->x;
        if (x_ret5) {
            c->fail = 3;
            return;
        } else {
            uint8_t value13 = RAM8(0x0000 + sp0 - 3);
            uint8_t value14 = RAM8(0x0000 + sp0 - 2);
            uint16_t value15 = BUS16_RDP(c, (db_ret3 << 0x10) + 0xA169);
            if (value15 == 4) {
                r->a = (r->a & 0x00FF) | (RAM8(0x0000 + sp0) << 8);
                r->y = (value14 << 8) | value13;
                r->c = value15 >= 4;
                r->mf = 1;
                r->xf = 0;
                RETURN_RTS(c);
            }
            uint8_t value18 = RAM8(0x0000 + sp0 - 1);
            uint8_t value19 = RAM8(0x0000 + sp0);
            if ((uint16_t)(((value19 << 8) | value18) - 1) != 0) {
                a1 = (uint8_t)(((value19 << 8) | value18) - 1);
                a_hi1 = (uint16_t)(((value19 << 8) | value18) - 1) >> 8;
                x1 = x_ret6;
                y1 = (uint16_t)(((value14 << 8) | value13) + 1);
                data_bank = db_ret3;
                direct_page = dp_ret3;
                continue;
            }
            uint16_t value20 = BUS16_RDP(c, (db_ret3 << 0x10) + 0xA169);
            uint8_t a3 = (uint8_t)(((value19 << 8) | value18) - 1);
            uint8_t a_hi3 = (uint16_t)(((value19 << 8) | value18) - 1) >> 8;
            uint16_t x3 = x_ret6;
            uint16_t y3 = value20;
            bool carry2 = value15 >= 4;
            bool overflow3 = overflow1;
            uint8_t data_bank3 = db_ret3;
            uint16_t direct_page3 = dp_ret3;
            for (;;) {
                r->a = (a_hi3 << 8) | a3;
                r->x = x3;
                r->y = y3;
                r->c = carry2;
                r->v = overflow3;
                r->mf = 1;
                r->xf = 0;
                r->db = data_bank3;
                r->dp = direct_page3;
                { const uint16_t sp_call = r->sp; JSR(c, 0x6925, 0xC7538D); GUARD_JSR(c, sp_call, 0x6925); } /* append_native_saved_slot_text_line_token */
                uint16_t dp_ret4 = r->dp;
                uint8_t db_ret4 = r->db;
                bool x_ret7 = r->xf;
                uint16_t a_all4 = r->a;
                uint16_t x_ret8 = r->x;
                if (x_ret7) {
                    c->fail = 3; /* operand size does not fit the register width on this path */
                    return;
                } else {
                    uint8_t a3_next = (uint8_t)a_all4;
                    uint8_t a_hi3_next = a_all4 >> 8;
                    uint16_t x3_next = x_ret8;
                    uint16_t y3_next = (uint16_t)(y3 + 1);
                    bool carry2_next = (uint16_t)(y3 + 1) >= 4;
                    uint8_t data_bank3_next = db_ret4;
                    uint16_t direct_page3_next = dp_ret4;
                    a3 = a3_next;
                    a_hi3 = a_hi3_next;
                    x3 = x3_next;
                    y3 = y3_next;
                    carry2 = carry2_next;
                    data_bank3 = data_bank3_next;
                    direct_page3 = direct_page3_next;
                }
                if (!(y3 != 4)) break;
            }
            r->a = (a_hi3 << 8) | a3;
            r->x = x3;
            r->y = y3;
            r->c = carry2;
            r->v = overflow3;
            r->mf = 1;
            r->xf = 0;
            r->db = data_bank3;
            r->dp = direct_page3;
            RETURN_RTS(c);
        }
    }
}
SOM_REGISTER(0xC768E7, SOM_RTS, "gen", append_first_four_native_party_status_restriction_labels, 0, L_B | L_X | L_Y | L_C | L_V, 6, 1, 0, 76, 39)
