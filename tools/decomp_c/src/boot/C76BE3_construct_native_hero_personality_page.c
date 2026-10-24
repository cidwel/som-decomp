#include "som_c.h"

/* C76BE3 construct_native_hero_personality_page   [class B, 98 bytes, 35 instructions]
 * Source: src/rom/construct_native_hero_personality_page.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: nothing.
 */
static void construct_native_hero_personality_page(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM8(0xA20F) = 4;
    uint8_t value = RAM8(0x19FE);
    RAM8(0xA22B) = value;
    uint8_t value2 = RAM8(0xA257 + value);
    RAM8(0xA136) = value2;
    r->a = value2;
    r->x = value;
    r->z = value2 == 0;
    r->n = value2 & 0x80;
    { const uint16_t sp_call = r->sp; JSL(c, 0x6BFC, 0xC02ACB); GUARD_JSL(c, sp_call, 0x6BFC); } /* construct_native_menu_page_long_call_wrapper */
    { const uint16_t sp_call = r->sp; JSR(c, 0x6BFF, 0xC76C58); GUARD_JSR(c, sp_call, 0x6BFF); } /* publish_native_skill_count_and_selector_rows */
    r->mf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0x6C03, 0xC02AD7); GUARD_JSL(c, sp_call, 0x6C03); } /* native_menu_tile_workspace_upload_long_wrapper */
    { const uint16_t sp_call = r->sp; JSL(c, 0x6C07, 0xC02ACF); GUARD_JSL(c, sp_call, 0x6C07); } /* clear_native_menu_sprite_tables_long_wrapper */
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6C0A, 0xC75DF9); GUARD_JSR(c, sp_call, 0x6C0A); } /* upload_native_party_page_tiles_and_three_palettes */
    uint8_t db_ret2 = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    bool x_ret8 = r->xf;
    uint16_t y_ret3 = r->y;
    uint8_t value3 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xA15A);
    BUS8_SET(c, (db_ret2 << 0x10) + 0xA175, value3);
    uint8_t value4 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xA22B);
    if (x_ret8) {
        uint8_t value5 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xCC7D + value4);
        uint8_t value6 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xA175);
        uint8_t a1;
        if (value5 < value6) {
            a1 = value5;
        } else {
            uint8_t value7 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xA175);
            a1 = value7;
        }
        BUS8_SET(c, (db_ret2 << 0x10) + 0xA211, a1);
        r->a = a1;
        r->x = value4;
        r->y = (uint8_t)y_ret3;
        r->c = value5 >= value6;
        r->xf = 1;
        { const uint16_t sp_call = r->sp; JSL(c, 0x6C29, 0xC76C45); GUARD_JSL(c, sp_call, 0x6C29); } /* derive_native_personality_selector_cursor_coordinates */
        r->mf = 1;
        r->xf = 1;
        { const uint16_t sp_call = r->sp; JSL(c, 0x6C2D, 0xC7503D); GUARD_JSL(c, sp_call, 0x6C2D); } /* publish_four_native_name_entry_cursor_corners */
        r->mf = 1;
        r->xf = 1;
        { const uint16_t sp_call = r->sp; JSL(c, 0x6C31, 0xC75217); GUARD_JSL(c, sp_call, 0x6C31); } /* dispatch_native_name_page_party_icon_variant */
        { const uint16_t sp_call = r->sp; JSL(c, 0x6C35, 0xC02AD3); GUARD_JSL(c, sp_call, 0x6C35); } /* upload_native_menu_sprite_tables_long_wrapper */
        uint8_t db_ret4 = r->db;
        { const uint16_t sp_call = r->sp; JSL(c, 0x6C39, 0xC02AC7); GUARD_JSL(c, sp_call, 0x6C39); } /* reset_native_menu_publication_long_wrapper */
        if (r->mf != 1) { c->fail = 3; return; }
        BUS8_SET(c, (db_ret4 << 0x10) + 0xA19F, 0x0A);
        uint8_t value8 = BUS8_RDP(c, (db_ret4 << 0x10) + 0xA212);
        BUS8_SET(c, (db_ret4 << 0x10) + 0xA212, value8 & 0xDF);
        RETURN_RTL(c);
    } else {
        uint8_t value9 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xCC7D + value4);
        uint8_t value10 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xA175);
        uint8_t a2;
        if (value9 < value10) {
            a2 = value9;
        } else {
            uint8_t value11 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xA175);
            a2 = value11;
        }
        BUS8_SET(c, (db_ret2 << 0x10) + 0xA211, a2);
        r->a = a2;
        r->x = value4;
        r->c = value9 >= value10;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0x6C29, 0xC76C45); GUARD_JSL(c, sp_call, 0x6C29); } /* derive_native_personality_selector_cursor_coordinates */
        r->mf = 1;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0x6C2D, 0xC7503D); GUARD_JSL(c, sp_call, 0x6C2D); } /* publish_four_native_name_entry_cursor_corners */
        r->mf = 1;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0x6C31, 0xC75217); GUARD_JSL(c, sp_call, 0x6C31); } /* dispatch_native_name_page_party_icon_variant */
        { const uint16_t sp_call = r->sp; JSL(c, 0x6C35, 0xC02AD3); GUARD_JSL(c, sp_call, 0x6C35); } /* upload_native_menu_sprite_tables_long_wrapper */
        uint8_t db_ret6 = r->db;
        { const uint16_t sp_call = r->sp; JSL(c, 0x6C39, 0xC02AC7); GUARD_JSL(c, sp_call, 0x6C39); } /* reset_native_menu_publication_long_wrapper */
        if (r->mf != 1) { c->fail = 3; return; }
        BUS8_SET(c, (db_ret6 << 0x10) + 0xA19F, 0x0A);
        uint8_t value12 = BUS8_RDP(c, (db_ret6 << 0x10) + 0xA212);
        BUS8_SET(c, (db_ret6 << 0x10) + 0xA212, value12 & 0xDF);
        RETURN_RTL(c);
    }
}
SOM_REGISTER(0xC76BE3, SOM_RTL, "gen", construct_native_hero_personality_page, 0, 0, 1, 1, 0, 98, 35)
