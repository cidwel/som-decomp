#include "som_c.h"

/* C02EE0 cycle_native_party_page_to_next_active_hero   [class B, 53 bytes, 22 instructions]
 * Source: src/rom/cycle_native_party_page_to_next_active_hero.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void cycle_native_party_page_to_next_active_hero(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = y >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)y;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x2EE3, 0xC0325A); GUARD_JSR(c, sp_call, 0x2EE3); } /* compare_selected_pad_buttons_against_native_previous_buttons */
    r->sp += 2;
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    bool carry_ret = r->c;
    bool zero_ret = r->z;
    bool x_flag3;
    uint8_t a3;
    uint8_t a_hi3;
    uint16_t x3;
    bool carry3;
    bool overflow3;
    uint8_t data_bank3;
    if (zero_ret) {
        x_flag3 = 0;
        a3 = (uint8_t)a_all;
        a_hi3 = a_all >> 8;
        x3 = x_ret;
        carry3 = carry_ret;
        overflow3 = overflow;
        data_bank3 = 0x7E;
    } else {
        uint8_t value = RAM8(0x19FE);
        r->a = (a_all >> 8 << 8) | value;
        r->z = value == 0;
        r->n = value & 0x80;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSL(c, 0x2EED, 0xC76BC7); GUARD_JSL(c, sp_call, 0x2EED); } /* advance_native_party_slot_with_three_slot_wrap */
        r->sp += 2;
        uint16_t a_all2 = r->a;
        r->y = a_all2;
        r->z = a_all2 == 0;
        r->n = a_all2 & 0x8000;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSL(c, 0x2EF2, 0xC76BB7); GUARD_JSL(c, sp_call, 0x2EF2); } /* load_native_party_slot_activity_minus_one */
        r->sp += 2;
        uint16_t a_all3 = r->a;
        bool zero_ret3 = r->z;
        bool x_flag2;
        uint8_t a2;
        uint8_t a_hi2;
        uint16_t x2;
        bool carry2;
        bool overflow2;
        uint8_t data_bank2;
        if (zero_ret3) {
            RAM8(0x19FE) = (uint8_t)a_all2;
            RAM8(0xA210) = 7;
            r->a = (a_all3 >> 8 << 8) | 7;
            r->z = 0;
            r->n = 0;
            r->mf = 1;
            r->xf = 0;
            r->sp -= 2;
            { const uint16_t sp_call = r->sp; JSR(c, 0x2F0D, 0xC01BA5); GUARD_JSR(c, sp_call, 0x2F0D); } /* preserve_accumulator_byte_and_request_fixed_local_audio_presets */
            r->sp += 2;
            uint8_t db_ret = r->db;
            if (r->mf != 1) { c->fail = 3; return; }
            bool x_ret3 = r->xf;
            uint16_t a_all4 = r->a;
            uint16_t x_ret4 = r->x;
            bool carry_ret4 = r->c;
            bool overflow_ret = r->v;
            uint8_t value2 = BUS8_RDP(c, (db_ret << 0x10) + 0xA20A);
            BUS8_SET(c, (db_ret << 0x10) + 0xA20A, value2 | 1);
            x_flag2 = x_ret3;
            a2 = 1;
            a_hi2 = a_all4 >> 8;
            x2 = x_ret4;
            carry2 = carry_ret4;
            overflow2 = overflow_ret;
            data_bank2 = db_ret;
        } else {
            r->a = (a_all3 >> 8 << 8) | (uint8_t)a_all2;
            r->z = (uint8_t)a_all2 == 0;
            r->n = (uint8_t)a_all2 & 0x80;
            r->mf = 1;
            r->xf = 0;
            r->sp -= 2;
            { const uint16_t sp_call = r->sp; JSL(c, 0x2EF9, 0xC76BC7); GUARD_JSL(c, sp_call, 0x2EF9); } /* advance_native_party_slot_with_three_slot_wrap */
            r->sp += 2;
            uint16_t a_all5 = r->a;
            r->y = a_all5;
            r->z = a_all5 == 0;
            r->n = a_all5 & 0x8000;
            r->mf = 1;
            r->xf = 0;
            r->sp -= 2;
            { const uint16_t sp_call = r->sp; JSL(c, 0x2EFE, 0xC76BB7); GUARD_JSL(c, sp_call, 0x2EFE); } /* load_native_party_slot_activity_minus_one */
            r->sp += 2;
            uint16_t a_all6 = r->a;
            uint16_t x_ret5 = r->x;
            bool carry_ret6 = r->c;
            bool zero_ret6 = r->z;
            bool x_flag;
            uint8_t a1;
            uint8_t a_hi1;
            uint16_t x1;
            bool carry1;
            bool overflow1;
            uint8_t data_bank;
            if (!zero_ret6) {
                x_flag = 0;
                a1 = (uint8_t)a_all6;
                a_hi1 = a_all6 >> 8;
                x1 = x_ret5;
                carry1 = carry_ret6;
                overflow1 = overflow;
                data_bank = 0x7E;
            } else {
                RAM8(0x19FE) = (uint8_t)a_all5;
                RAM8(0xA210) = 7;
                r->a = (a_all6 >> 8 << 8) | 7;
                r->z = 0;
                r->n = 0;
                r->mf = 1;
                r->xf = 0;
                r->sp -= 2;
                { const uint16_t sp_call = r->sp; JSR(c, 0x2F0D, 0xC01BA5); GUARD_JSR(c, sp_call, 0x2F0D); } /* preserve_accumulator_byte_and_request_fixed_local_audio_presets */
                r->sp += 2;
                uint8_t db_ret2 = r->db;
                if (r->mf != 1) { c->fail = 3; return; }
                bool x_ret6 = r->xf;
                uint16_t a_all7 = r->a;
                uint16_t x_ret7 = r->x;
                bool carry_ret7 = r->c;
                bool overflow_ret2 = r->v;
                uint8_t value3 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xA20A);
                BUS8_SET(c, (db_ret2 << 0x10) + 0xA20A, value3 | 1);
                x_flag = x_ret6;
                a1 = 1;
                a_hi1 = a_all7 >> 8;
                x1 = x_ret7;
                carry1 = carry_ret7;
                overflow1 = overflow_ret2;
                data_bank = db_ret2;
            }
            x_flag2 = x_flag;
            a2 = a1;
            a_hi2 = a_hi1;
            x2 = x1;
            carry2 = carry1;
            overflow2 = overflow1;
            data_bank2 = data_bank;
        }
        x_flag3 = x_flag2;
        a3 = a2;
        a_hi3 = a_hi2;
        x3 = x2;
        carry3 = carry2;
        overflow3 = overflow2;
        data_bank3 = data_bank2;
    }
    if (x_flag3) {
        c->fail = 3;
        return;
    } else {
        uint8_t value5 = RAM8(0x0000 + sp0 - 1);
        uint8_t value6 = RAM8(0x0000 + sp0);
        r->a = (a_hi3 << 8) | a3;
        r->x = x3;
        r->y = (value6 << 8) | value5;
        r->c = carry3;
        r->z = ((value6 << 8) | value5) == 0;
        r->n = ((value6 << 8) | value5) & 0x8000;
        r->v = overflow3;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank3;
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC02EE0, SOM_RTS, "gen", cycle_native_party_page_to_next_active_hero, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 2, 1, 0, 53, 22)
