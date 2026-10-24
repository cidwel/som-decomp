#include "som_c.h"

/* C75229 construct_native_title_load_selection_from_validated_saved_slots   [class B, 74 bytes, 26 instructions]
 * Source: src/rom/construct_native_title_load_selection_from_validated_saved_slots.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: nothing.
 */
static void construct_native_title_load_selection_from_validated_saved_slots(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    r->a = (a_hi << 8) | 8;
    r->z = 0;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0x522E, 0xC02B02); GUARD_JSL(c, sp_call, 0x522E); } /* request_local_audio_preset_long */
    uint8_t db_ret = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    uint16_t a_all = r->a;
    BUS8_SET(c, (db_ret << 0x10) + 0xA220, 0);
    BUS8_SET(c, (db_ret << 0x10) + 0xA20F, 0);
    r->a = (a_all >> 8 << 8) | 0;
    r->z = 1;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0x523A, 0xC02ACB); GUARD_JSL(c, sp_call, 0x523A); } /* construct_native_menu_page_long_call_wrapper */
    { const uint16_t sp_call = r->sp; JSL(c, 0x523E, 0xC02ACF); GUARD_JSL(c, sp_call, 0x523E); } /* clear_native_menu_sprite_tables_long_wrapper */
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0x5242, 0xC02AD3); GUARD_JSL(c, sp_call, 0x5242); } /* upload_native_menu_sprite_tables_long_wrapper */
    uint8_t db_ret3 = r->db;
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0x5246, 0xC7595C); GUARD_JSL(c, sp_call, 0x5246); } /* upload_native_saved_slot_six_byte_palette */
    uint16_t a_all5 = r->a;
    BUS8_SET(c, (db_ret3 << 0x10) + 0xA211, 0);
    r->a = (a_all5 >> 8 << 8) | 0;
    r->z = 1;
    r->n = 0;
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x524E, 0xC75BCA); GUARD_JSR(c, sp_call, 0x524E); } /* validate_four_native_save_slot_signatures_copies_and_checksums */
    uint8_t db_ret4 = r->db;
    uint16_t a_all6 = r->a;
    uint8_t value = BUS8_RDP(c, (db_ret4 << 0x10) + 0xA215);
    if ((uint8_t)(value + 1) == 0) {
        BUS8_SET(c, 0x307FFF, 0);
    } else {
        uint8_t value2 = BUS8_RDP(c, (db_ret4 << 0x10) + 0xA211);
        BUS8_SET(c, (db_ret4 << 0x10) + 0xA211, (uint8_t)(value2 + 1));
    }
    BUS8_SET(c, (db_ret4 << 0x10) + 0xA202, 6);
    r->a = (a_all6 >> 8 << 8) | 6;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0x5268, 0xC757DC); GUARD_JSL(c, sp_call, 0x5268); } /* highlight_native_saved_slot_rectangle_and_request_publication */
    uint8_t db_ret5 = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    uint16_t a_all7 = r->a;
    BUS8_SET(c, (db_ret5 << 0x10) + 0xA202, 0);
    r->a = (a_all7 >> 8 << 8) | 0;
    r->z = 1;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0x5271, 0xC02AC7); GUARD_JSL(c, sp_call, 0x5271); } /* reset_native_menu_publication_long_wrapper */
    r->mf = 1;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC75229, SOM_RTL, "gen", construct_native_title_load_selection_from_validated_saved_slots, 0, 0, 1, 1, 0, 74, 26)
