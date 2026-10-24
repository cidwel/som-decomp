#include "som_c.h"

/* C02F15 confirm_native_personality_selection_or_open_selector   [class B, 44 bytes, 17 instructions]
 * Source: src/rom/confirm_native_personality_selection_or_open_selector.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void confirm_native_personality_selection_or_open_selector(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t y = r->y;
    const bool overflow = r->v;
    { const uint16_t sp_call = r->sp; JSR(c, 0x2F17, 0xC0325A); GUARD_JSR(c, sp_call, 0x2F17); } /* compare_selected_pad_buttons_against_native_previous_buttons */
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    bool carry_ret = r->c;
    bool zero_ret = r->z;
    bool negative_ret = r->n;
    bool x_flag2;
    uint8_t a1;
    uint8_t a_hi2;
    uint16_t x2;
    uint16_t y2;
    bool carry2;
    bool zero2;
    bool negative1;
    bool overflow2;
    uint8_t data_bank2;
    uint16_t direct_page2;
    if (zero_ret) {
        x_flag2 = 0;
        a1 = (uint8_t)a_all;
        a_hi2 = a_all >> 8;
        x2 = x_ret;
        y2 = y;
        carry2 = carry_ret;
        zero2 = zero_ret;
        negative1 = negative_ret;
        overflow2 = overflow;
        data_bank2 = 0x7E;
        direct_page2 = 0;
    } else {
        uint8_t value = RAM8(0xA212);
        bool x_flag;
        uint8_t a_hi1;
        uint16_t x1;
        uint16_t y1;
        bool carry1;
        bool zero1;
        bool overflow1;
        uint8_t data_bank;
        uint16_t direct_page;
        if ((value & 0x20) != 0) {
            r->a = (a_all >> 8 << 8) | value;
            r->z = (value & 0x20) == 0;
            r->n = value & 0x80;
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSL(c, 0x2F35, 0xC76CA7); GUARD_JSL(c, sp_call, 0x2F35); } /* commit_native_hero_personality_and_reinitialize_actor_program */
            if (r->mf != 1) { c->fail = 3; return; }
            bool x_ret2 = r->xf;
            uint16_t a_all2 = r->a;
            uint16_t x_ret3 = r->x;
            uint16_t y_ret = r->y;
            bool carry_ret2 = r->c;
            bool overflow_ret = r->v;
            RAM8(0xA20A) |= 1;
            uint8_t value3 = RAM8(0xA212);
            RAM8(0xA212) &= 0xDF;
            x_flag = x_ret2;
            a_hi1 = a_all2 >> 8;
            x1 = x_ret3;
            y1 = y_ret;
            carry1 = carry_ret2;
            zero1 = (value3 & 0x20) == 0;
            overflow1 = overflow_ret;
            data_bank = 0x7E;
            direct_page = 0;
        } else {
            r->a = (a_all >> 8 << 8) | value;
            r->z = (value & 0x20) == 0;
            r->n = value & 0x80;
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x2F23, 0xC01BA5); GUARD_JSR(c, sp_call, 0x2F23); } /* preserve_accumulator_byte_and_request_fixed_local_audio_presets */
            bool overflow_ret2 = r->v;
            { const uint16_t sp_call = r->sp; JSR(c, 0x2F26, 0xC01EFD); GUARD_JSR(c, sp_call, 0x2F26); } /* highlight_native_menu_actor_sprite_palette */
            uint16_t y_ret3 = r->y;
            bool carry_ret4 = r->c;
            { const uint16_t sp_call = r->sp; JSL(c, 0x2F2A, 0xC76D5C); GUARD_JSL(c, sp_call, 0x2F2A); } /* external */
            uint16_t dp_ret = r->dp;
            uint8_t db_ret2 = r->db;
            if (r->mf != 1) { c->fail = 3; return; }
            bool x_ret8 = r->xf;
            uint16_t a_all5 = r->a;
            uint16_t x_ret9 = r->x;
            uint8_t value4 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xA212);
            BUS8_SET(c, (db_ret2 << 0x10) + 0xA212, value4 | 0x20);
            x_flag = x_ret8;
            a_hi1 = a_all5 >> 8;
            x1 = x_ret9;
            y1 = y_ret3;
            carry1 = carry_ret4;
            zero1 = (value4 & 0x20) == 0;
            overflow1 = overflow_ret2;
            data_bank = db_ret2;
            direct_page = dp_ret;
        }
        x_flag2 = x_flag;
        a1 = 0x20;
        a_hi2 = a_hi1;
        x2 = x1;
        y2 = y1;
        carry2 = carry1;
        zero2 = zero1;
        negative1 = 0;
        overflow2 = overflow1;
        data_bank2 = data_bank;
        direct_page2 = direct_page;
    }
    r->a = (a_hi2 << 8) | a1;
    r->x = x2;
    r->y = y2;
    r->c = carry2;
    r->z = zero2;
    r->n = negative1;
    r->v = overflow2;
    r->mf = 1;
    r->xf = x_flag2;
    r->db = data_bank2;
    r->dp = direct_page2;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC02F15, SOM_RTS, "gen", confirm_native_personality_selection_or_open_selector, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 44, 17)
