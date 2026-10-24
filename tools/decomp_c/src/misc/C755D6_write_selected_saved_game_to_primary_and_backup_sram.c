#include "som_c.h"

/* C755D6 write_selected_saved_game_to_primary_and_backup_sram   [class B, 66 bytes, 26 instructions]
 * Source: src/rom/write_selected_saved_game_to_primary_and_backup_sram.s
 * Documented in docs/ui-native-loaded-game-save-write.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BV.
 */
static void write_selected_saved_game_to_primary_and_backup_sram(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    { const uint16_t sp_call = r->sp; JSR(c, 0x55D8, 0xC757C6); GUARD_JSR(c, sp_call, 0x55D8); } /* derive_primary_sram_slot_offset_from_selected_index */
    uint16_t x_ret = r->x;
    RAM8(0x0000 + sp0) = x_ret >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)x_ret;
    r->x = (uint16_t)(x_ret + 3);
    r->y = 0xCC00;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x55E2, 0xC756E1); GUARD_JSR(c, sp_call, 0x55E2); } /* pack_128_wram_bytes_into_two_sram_slot_copies */
    r->sp += 2;
    r->y = 0xCF00;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x55E8, 0xC756F6); GUARD_JSR(c, sp_call, 0x55E8); } /* pack_128_wram_nibble_pairs_into_two_sram_slot_copies */
    r->sp += 2;
    r->y = 0xE180;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x55EE, 0xC756E1); GUARD_JSR(c, sp_call, 0x55EE); } /* pack_128_wram_bytes_into_two_sram_slot_copies */
    r->sp += 2;
    r->y = 0xE380;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x55F4, 0xC756E1); GUARD_JSR(c, sp_call, 0x55F4); } /* pack_128_wram_bytes_into_two_sram_slot_copies */
    r->sp += 2;
    r->y = 0xE580;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x55FA, 0xC756E1); GUARD_JSR(c, sp_call, 0x55FA); } /* pack_128_wram_bytes_into_two_sram_slot_copies */
    r->sp += 2;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x55FD, 0xC7571E); GUARD_JSR(c, sp_call, 0x55FD); } /* pack_three_party_name_prefixes_into_saved_slot */
    r->sp += 2;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5600, 0xC75731); GUARD_JSR(c, sp_call, 0x5600); } /* pack_low_bank_map_position_into_saved_slot */
    r->sp += 2;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5603, 0xC7574F); GUARD_JSR(c, sp_call, 0x5603); } /* select_active_controller_binding_and_pack_low_nibble */
    r->sp += 2;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5606, 0xC7576F); GUARD_JSR(c, sp_call, 0x5606); } /* pack_seventeen_menu_bytes_into_saved_slot */
    r->sp += 2;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5609, 0xC7579F); GUARD_JSR(c, sp_call, 0x5609); } /* pack_menu_word_into_two_copies_and_advance_cursor */
    r->sp += 2;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x560C, 0xC75787); GUARD_JSR(c, sp_call, 0x560C); } /* pack_twelve_menu_bytes_into_saved_slot */
    r->sp += 2;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x560F, 0xC75618); GUARD_JSR(c, sp_call, 0x560F); } /* advance_native_save_serial_and_propagate_counter_to_valid_slots */
    r->sp += 2;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5612, 0xC756D0); GUARD_JSR(c, sp_call, 0x5612); } /* write_current_map_word_to_both_saved_slot_copies */
    r->sp += 2;
    r->x = (RAM8(0x0000 + sp0) << 8) | RAM8(0x0000 + sp0 - 1);
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5616, 0xC756A9); GUARD_JSR(c, sp_call, 0x5616); } /* write_two_save_signatures_and_checksum_primary_payload */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC755D6, SOM_RTL, "gen", write_selected_saved_game_to_primary_and_backup_sram, 0, L_B | L_V, 2, 1, 0, 66, 26)
