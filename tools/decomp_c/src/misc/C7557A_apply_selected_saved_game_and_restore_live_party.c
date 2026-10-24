#include "som_c.h"

/* C7557A apply_selected_saved_game_and_restore_live_party   [class B, 92 bytes, 36 instructions]
 * Source: src/rom/apply_selected_saved_game_and_restore_live_party.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BV.
 */
static void apply_selected_saved_game_and_restore_live_party(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    uint8_t value = RAM8(0xA211);
    BUS8_SET(c, 0x307FFF, value);
    r->a = (a_hi << 8) | value;
    r->z = value == 0;
    r->n = value & 0x80;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5583, 0xC7583C); GUARD_JSR(c, sp_call, 0x5583); } /* select_save_slot_copy_and_reject_invalid_pair */
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    bool overflow_ret = r->v;
    uint8_t value2 = RAM8(0xA212);
    uint8_t a_hi1;
    bool overflow1;
    uint8_t data_bank;
    uint16_t direct_page;
    if ((value2 & 4) != 0) {
        a_hi1 = a_all >> 8;
        overflow1 = overflow_ret;
        data_bank = 0x7E;
        direct_page = 0x0300;
    } else {
        RAM8(0x0000 + sp0) = (uint16_t)(x_ret + 1) >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)(x_ret + 1);
        r->a = (a_all >> 8 << 8) | value2;
        r->x = (uint16_t)(x_ret + 3);
        r->y = 0xCC00;
        r->z = 0;
        r->n = 1;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSR(c, 0x5594, 0xC7587A); GUARD_JSR(c, sp_call, 0x5594); } /* unpack_128_save_bytes_into_wram */
        r->sp += 2;
        r->y = 0xCF00;
        r->z = 0;
        r->n = 1;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSR(c, 0x559A, 0xC7588B); GUARD_JSR(c, sp_call, 0x559A); } /* unpack_128_save_nibble_pairs_into_wram */
        r->sp += 2;
        r->y = 0xE180;
        r->z = 0;
        r->n = 1;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSR(c, 0x55A0, 0xC7587A); GUARD_JSR(c, sp_call, 0x55A0); } /* unpack_128_save_bytes_into_wram */
        r->sp += 2;
        r->y = 0xE380;
        r->z = 0;
        r->n = 1;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSR(c, 0x55A6, 0xC7587A); GUARD_JSR(c, sp_call, 0x55A6); } /* unpack_128_save_bytes_into_wram */
        r->sp += 2;
        r->y = 0xE580;
        r->z = 0;
        r->n = 1;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSR(c, 0x55AC, 0xC7587A); GUARD_JSR(c, sp_call, 0x55AC); } /* unpack_128_save_bytes_into_wram */
        r->sp += 2;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSR(c, 0x55AF, 0xC758A8); GUARD_JSR(c, sp_call, 0x55AF); } /* unpack_three_saved_actor_name_prefixes */
        r->sp += 2;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSR(c, 0x55B2, 0xC758D1); GUARD_JSR(c, sp_call, 0x55B2); } /* unpack_saved_map_position_to_low_bank_globals */
        r->sp += 2;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSR(c, 0x55B5, 0xC758FA); GUARD_JSR(c, sp_call, 0x55B5); } /* restore_first_controller_binding_and_clear_other_two */
        r->sp += 2;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSR(c, 0x55B8, 0xC75906); GUARD_JSR(c, sp_call, 0x55B8); } /* unpack_seventeen_saved_menu_bytes */
        r->sp += 2;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSR(c, 0x55BB, 0xC7592E); GUARD_JSR(c, sp_call, 0x55BB); } /* unpack_saved_menu_word_and_advance_sram_cursor */
        r->sp += 2;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSR(c, 0x55BE, 0xC7591A); GUARD_JSR(c, sp_call, 0x55BE); } /* unpack_eight_saved_menu_bytes */
        r->sp += 2;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSR(c, 0x55C1, 0xC75948); GUARD_JSR(c, sp_call, 0x55C1); } /* unpack_three_saved_menu_bytes */
        r->sp += 2;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSR(c, 0x55C4, 0xC758EB); GUARD_JSR(c, sp_call, 0x55C4); } /* read_saved_map_word_after_skipping_two_bytes */
        r->sp += 2;
        uint8_t value3 = RAM8(0x0000 + sp0 - 1);
        uint8_t value4 = RAM8(0x0000 + sp0);
        RAM8(0x0000 + sp0) = value4;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)((value4 << 8) | value3);
        r->x = (value4 << 8) | value3;
        r->z = ((value4 << 8) | value3) == 0;
        r->n = ((value4 << 8) | value3) & 0x8000;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSL(c, 0x55CA, 0xC00021); GUARD_JSL(c, sp_call, 0x55CA); } /* restore_loaded_party_actor_records_public_jump */
        r->sp += 2;
        uint16_t dp_ret = r->dp;
        uint8_t db_ret2 = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all15 = r->a;
        bool overflow_ret3 = r->v;
        RAM8(0x011F) = 0xFE;
        uint8_t value5 = RAM8(0x0000 + sp0 - 1);
        uint8_t value6 = RAM8(0x0000 + sp0);
        r->a = (a_all15 >> 8 << 8) | 0xFE;
        r->x = (value6 << 8) | value5;
        r->z = ((value6 << 8) | value5) == 0;
        r->n = ((value6 << 8) | value5) & 0x8000;
        { const uint16_t sp_call = r->sp; JSR(c, 0x55D4, 0xC7593C); GUARD_JSR(c, sp_call, 0x55D4); } /* read_saved_menu_word_without_advancing_sram_cursor */
        uint16_t a_all16 = r->a;
        a_hi1 = a_all16 >> 8;
        overflow1 = overflow_ret3;
        data_bank = db_ret2;
        direct_page = dp_ret;
    }
    r->a = (a_hi1 << 8) | a;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank;
    r->dp = direct_page;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC7557A, SOM_RTL, "gen", apply_selected_saved_game_and_restore_live_party, 0, L_B | L_V, 2, 1, 0, 92, 36)
