#include "som_c.h"

/* C29381 advance_native7f_timed_spell_state_or_enter_death_palette_phase   [class B, 74 bytes, 29 instructions]
 * Source: src/rom/advance_native7f_timed_spell_state_or_enter_death_palette_phase.s
 * Entry: M=16 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void advance_native7f_timed_spell_state_or_enter_death_palette_phase(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    const uint16_t dp = r->dp;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint16_t value = BUS16_RDP(c, (uint16_t)(dp + 0x87));
    if (RAM16(0x0190 + value) & 0x8000) {
        RAM16_SET(OBJECT_PHASE + value, 0x12);
        RAM16_SET(OBJECT_AGE + value, 0);
        r->a = 0x78;
        r->x = 0x84;
        r->y = 0x0D;
        r->z = 0;
        r->n = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x93BC, 0xC2272D); GUARD_JSR(c, sp_call, 0x93BC); } /* allocate_boss_palette_transition_object */
        r->a = 0x78;
        r->x = 0x85;
        r->y = 0x0E;
        r->z = 0;
        r->n = 0;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x93C8, 0xC2272D); GUARD_JSR(c, sp_call, 0x93C8); } /* allocate_boss_palette_transition_object */
        r->c = 0;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint16_t value3 = RAM16(0x00AD + value);
    uint16_t value4 = RAM16(0x002D + value);
    bool x_flag;
    uint8_t a_hi1;
    uint16_t y1;
    bool overflow1;
    uint8_t data_bank;
    uint16_t direct_page;
    if (value3 < value4) {
        x_flag = 0;
        a_hi1 = value3 >> 8;
        y1 = y;
        overflow1 = overflow;
        data_bank = 0x7E;
        direct_page = dp;
    } else {
        r->a = value3;
        r->x = value;
        r->c = value3 >= value4;
        r->z = value3 == value4;
        r->n = (uint16_t)(value3 - value4) & 0x8000;
        { const uint16_t sp_call = r->sp; JSR(c, 0x9392, 0xC23372); GUARD_JSR(c, sp_call, 0x9392); } /* derive_boss_hp_gate_from_byte_189_with_wrapped_subtraction */
        RAM16_SET(0x00AD + value, 0);
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x9398, 0xC293CB); GUARD_JSR(c, sp_call, 0x9398); } /* select_native7f_nearest_target_and_primary_spell_gate */
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        if (r->mf != 0) { c->fail = 3; return; }
        bool x_ret3 = r->xf;
        uint16_t a_all4 = r->a;
        uint16_t y_ret3 = r->y;
        bool overflow_ret4 = r->v;
        x_flag = x_ret3;
        a_hi1 = a_all4 >> 8;
        y1 = y_ret3;
        overflow1 = overflow_ret4;
        data_bank = db_ret;
        direct_page = dp_ret;
    }
    if (x_flag) {
        uint8_t value5 = BUS8_RDP(c, (uint16_t)(direct_page + 0x87));
        uint16_t value6 = BUS16_RDP(c, (data_bank << 0x10) + 0x96 + value5);
        bool zero1;
        bool negative1;
        if (value6 < 0xF0) {
            zero1 = value6 == 0xF0;
            negative1 = (uint16_t)(value6 - 0xF0) & 0x8000;
        } else {
            uint16_t value7 = BUS16_RDP(c, (data_bank << 0x10) + 0x94 + value5);
            BUS16_RMW_SET(c, (data_bank << 0x10) + 0x94 + value5, (uint16_t)(value7 + 1));
            zero1 = (uint16_t)(value7 + 1) == 0;
            negative1 = (uint16_t)(value7 + 1) & 0x8000;
        }
        r->a = value6;
        r->x = value5;
        r->y = (uint8_t)y1;
        r->c = 0;
        r->z = zero1;
        r->n = negative1;
        r->v = overflow1;
        r->xf = 1;
        r->db = data_bank;
        r->dp = direct_page;
        RETURN_RTS(c);
    } else {
        uint16_t value8 = BUS16_RDP(c, (uint16_t)(direct_page + 0x87));
        uint16_t value9 = BUS16_RDP(c, (data_bank << 0x10) + 0x96 + value8);
        bool zero2;
        bool negative2;
        if (value9 < 0xF0) {
            zero2 = value9 == 0xF0;
            negative2 = (uint16_t)(value9 - 0xF0) & 0x8000;
        } else {
            uint16_t value10 = BUS16_RDP(c, (data_bank << 0x10) + 0x94 + value8);
            BUS16_RMW_SET(c, (data_bank << 0x10) + 0x94 + value8, (uint16_t)(value10 + 1));
            zero2 = (uint16_t)(value10 + 1) == 0;
            negative2 = (uint16_t)(value10 + 1) & 0x8000;
        }
        r->a = value9;
        r->x = value8;
        r->y = y1;
        r->c = 0;
        r->z = zero2;
        r->n = negative2;
        r->v = overflow1;
        r->xf = 0;
        r->db = data_bank;
        r->dp = direct_page;
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC29381, SOM_RTS, "gen", advance_native7f_timed_spell_state_or_enter_death_palette_phase, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 74, 29)
