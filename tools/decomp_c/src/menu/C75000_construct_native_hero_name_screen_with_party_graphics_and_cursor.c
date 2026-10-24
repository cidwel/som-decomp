#include "som_c.h"

/* C75000 construct_native_hero_name_screen_with_party_graphics_and_cursor   [class B, 61 bytes, 20 instructions]
 * Source: src/rom/construct_native_hero_name_screen_with_party_graphics_and_cursor.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: nothing.
 */
static void construct_native_hero_name_screen_with_party_graphics_and_cursor(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSR(c, 0x5002, 0xC75DDC); GUARD_JSR(c, sp_call, 0x5002); } /* select_first_active_native_menu_party_hero */
    uint16_t a_all = r->a;
    RAM8(0xA20F) = 3;
    r->a = (a_all >> 8 << 8) | 3;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0x500B, 0xC02ACB); GUARD_JSL(c, sp_call, 0x500B); } /* construct_native_menu_page_long_call_wrapper */
    { const uint16_t sp_call = r->sp; JSR(c, 0x500E, 0xC75DF9); GUARD_JSR(c, sp_call, 0x500E); } /* upload_native_party_page_tiles_and_three_palettes */
    { const uint16_t sp_call = r->sp; JSL(c, 0x5012, 0xC02ACF); GUARD_JSL(c, sp_call, 0x5012); } /* clear_native_menu_sprite_tables_long_wrapper */
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0x5016, 0xC75217); GUARD_JSL(c, sp_call, 0x5016); } /* dispatch_native_name_page_party_icon_variant */
    uint8_t db_ret3 = r->db;
    if (r->xf != 0) { c->fail = 3; return; }
    BUS16_SET(c, (db_ret3 << 0x10) + 0xA159, 0x6013);
    r->x = 0x6013;
    r->z = 0;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0x5020, 0xC7503D); GUARD_JSL(c, sp_call, 0x5020); } /* publish_four_native_name_entry_cursor_corners */
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0x5024, 0xC02AD3); GUARD_JSL(c, sp_call, 0x5024); } /* upload_native_menu_sprite_tables_long_wrapper */
    uint8_t db_ret4 = r->db;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0x5028, 0xC02AC7); GUARD_JSL(c, sp_call, 0x5028); } /* reset_native_menu_publication_long_wrapper */
    if (r->mf != 1) { c->fail = 3; return; }
    BUS8_SET(c, (db_ret4 << 0x10) + 0xA157, 0x12);
    BUS8_SET(c, (db_ret4 << 0x10) + 0xA158, 0);
    BUS8_SET(c, (db_ret4 << 0x10) + 0xA156, 3);
    BUS8_SET(c, (db_ret4 << 0x10) + 0xA162, 0);
    BUS8_SET(c, (db_ret4 << 0x10) + 0xA1CC, 0);
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC75000, SOM_RTL, "gen", construct_native_hero_name_screen_with_party_graphics_and_cursor, 0, 0, 1, 1, 0, 61, 20)
