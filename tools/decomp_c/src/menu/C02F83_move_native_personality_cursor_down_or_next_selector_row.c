#include "som_c.h"

/* C02F83 move_native_personality_cursor_down_or_next_selector_row   [class B, 69 bytes, 29 instructions]
 * Source: src/rom/move_native_personality_cursor_down_or_next_selector_row.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void move_native_personality_cursor_down_or_next_selector_row(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t y = r->y;
    const bool overflow = r->v;
    { const uint16_t sp_call = r->sp; JSR(c, 0x2F85, 0xC0325A); GUARD_JSR(c, sp_call, 0x2F85); } /* compare_selected_pad_buttons_against_native_previous_buttons */
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    bool carry_ret = r->c;
    bool zero_ret = r->z;
    bool negative_ret = r->n;
    bool x_flag2;
    uint8_t a5;
    uint8_t a_hi2;
    uint16_t x2;
    uint16_t y2;
    bool carry3;
    bool zero3;
    bool negative3;
    bool overflow3;
    uint8_t data_bank2;
    uint16_t direct_page2;
    if (zero_ret) {
        x_flag2 = 0;
        a5 = (uint8_t)a_all;
        a_hi2 = a_all >> 8;
        x2 = x_ret;
        y2 = y;
        carry3 = carry_ret;
        zero3 = zero_ret;
        negative3 = negative_ret;
        overflow3 = overflow;
        data_bank2 = 0x7E;
        direct_page2 = 0;
    } else {
        r->mf = 1;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x2F8A, 0xC01BAA); GUARD_JSR(c, sp_call, 0x2F8A); } /* external */
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        uint16_t a_all2 = r->a;
        bool overflow_ret = r->v;
        uint8_t value = BUS8_RDP(c, (db_ret << 0x10) + 0xA212);
        bool x_flag;
        uint8_t a4;
        uint8_t a_hi1;
        uint16_t x1;
        uint16_t y1;
        bool carry2;
        bool zero2;
        bool negative2;
        bool overflow2;
        uint8_t data_bank;
        uint16_t direct_page;
        if ((value & 0x20) != 0) {
            uint8_t value2 = BUS8_RDP(c, (db_ret << 0x10) + 0xA211);
            uint8_t value3 = BUS8_RDP(c, (db_ret << 0x10) + 0xA200);
            uint8_t a1;
            bool zero1;
            bool negative1;
            if ((uint8_t)(value2 + 1) != value3) {
                a1 = (uint8_t)(value2 + 1);
                zero1 = (uint8_t)(value2 + 1) == value3;
                negative1 = (uint8_t)((uint8_t)(value2 + 1) - value3) & 0x80;
            } else {
                a1 = 0;
                zero1 = 1;
                negative1 = 0;
            }
            BUS8_SET(c, (db_ret << 0x10) + 0xA211, a1);
            r->a = (a_all2 >> 8 << 8) | a1;
            r->c = (uint8_t)(value2 + 1) >= value3;
            r->z = zero1;
            r->n = negative1;
            { const uint16_t sp_call = r->sp; JSL(c, 0x2FC2, 0xC76C45); GUARD_JSL(c, sp_call, 0x2FC2); } /* derive_native_personality_selector_cursor_coordinates */
            r->mf = 1;
            { const uint16_t sp_call = r->sp; JSL(c, 0x2FC6, 0xC7503D); GUARD_JSL(c, sp_call, 0x2FC6); } /* publish_four_native_name_entry_cursor_corners */
            bool x_ret5 = r->xf;
            uint16_t a_all4 = r->a;
            uint16_t x_ret6 = r->x;
            uint16_t y_ret2 = r->y;
            bool carry_ret4 = r->c;
            bool zero_ret4 = r->z;
            bool negative_ret4 = r->n;
            bool overflow_ret3 = r->v;
            x_flag = x_ret5;
            a4 = (uint8_t)a_all4;
            a_hi1 = a_all4 >> 8;
            x1 = x_ret6;
            y1 = y_ret2;
            carry2 = carry_ret4;
            zero2 = zero_ret4;
            negative2 = negative_ret4;
            overflow2 = overflow_ret3;
            data_bank = db_ret;
            direct_page = dp_ret;
        } else {
            uint8_t value4 = BUS8_RDP(c, (db_ret << 0x10) + 0xA136);
            uint8_t a3;
            bool carry1;
            bool overflow1;
            if (value4 == 0x0F) {
                a3 = (uint8_t)(value4 + 1);
                carry1 = value4 >= 0x0F;
                overflow1 = overflow_ret;
            } else {
                uint8_t a2;
                if ((uint8_t)(value4 + 4) < 0x10) {
                    a2 = (uint8_t)(value4 + 4);
                } else {
                    a2 = (uint8_t)(value4 + 5);
                }
                a3 = a2;
                carry1 = (uint8_t)(value4 + 4) >= 0x10;
                overflow1 = ((value4 ^ (uint8_t)(value4 + 4)) & ((uint8_t)(value4 + 4) ^ 4) & 0x80) != 0;
            }
            BUS8_SET(c, (db_ret << 0x10) + 0xA136, a3 & 0x0F);
            r->a = a_all2 >> 8 << 8 | (a3 & 0x0F);
            r->c = carry1;
            r->z = (a3 & 0x0F) == 0;
            r->n = a3 & 0x0F & 0x80;
            r->v = overflow1;
            { const uint16_t sp_call = r->sp; JSL(c, 0x2FA9, 0xC75217); GUARD_JSL(c, sp_call, 0x2FA9); } /* dispatch_native_name_page_party_icon_variant */
            uint16_t dp_ret2 = r->dp;
            uint8_t db_ret2 = r->db;
            if (r->mf != 1) { c->fail = 3; return; }
            bool x_ret7 = r->xf;
            uint16_t a_all5 = r->a;
            uint16_t x_ret8 = r->x;
            uint16_t y_ret3 = r->y;
            bool carry_ret5 = r->c;
            bool overflow_ret4 = r->v;
            uint8_t value5 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xA20A);
            BUS8_SET(c, (db_ret2 << 0x10) + 0xA20A, value5 | 4);
            x_flag = x_ret7;
            a4 = 4;
            a_hi1 = a_all5 >> 8;
            x1 = x_ret8;
            y1 = y_ret3;
            carry2 = carry_ret5;
            zero2 = (value5 & 4) == 0;
            negative2 = 0;
            overflow2 = overflow_ret4;
            data_bank = db_ret2;
            direct_page = dp_ret2;
        }
        x_flag2 = x_flag;
        a5 = a4;
        a_hi2 = a_hi1;
        x2 = x1;
        y2 = y1;
        carry3 = carry2;
        zero3 = zero2;
        negative3 = negative2;
        overflow3 = overflow2;
        data_bank2 = data_bank;
        direct_page2 = direct_page;
    }
    r->a = (a_hi2 << 8) | a5;
    r->x = x2;
    r->y = y2;
    r->c = carry3;
    r->z = zero3;
    r->n = negative3;
    r->v = overflow3;
    r->mf = 1;
    r->xf = x_flag2;
    r->db = data_bank2;
    r->dp = direct_page2;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC02F83, SOM_RTS, "gen", move_native_personality_cursor_down_or_next_selector_row, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 69, 29)
