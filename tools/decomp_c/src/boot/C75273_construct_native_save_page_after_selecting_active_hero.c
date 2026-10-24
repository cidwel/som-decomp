#include "som_c.h"

/* C75273 construct_native_save_page_after_selecting_active_hero   [class B, 60 bytes, 20 instructions]
 * Source: src/rom/construct_native_save_page_after_selecting_active_hero.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: nothing.
 */
static void construct_native_save_page_after_selecting_active_hero(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSR(c, 0x5275, 0xC75DDC); GUARD_JSR(c, sp_call, 0x5275); } /* select_first_active_native_menu_party_hero */
    uint16_t a_all = r->a;
    RAM8(0xA20F) = 0xFF;
    uint8_t value = RAM8(0xA212);
    RAM8(0xA212) |= 2;
    r->a = (a_all >> 8 << 8) | 2;
    r->z = (value & 2) == 0;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0x5288, 0xC02ACB); GUARD_JSL(c, sp_call, 0x5288); } /* construct_native_menu_page_long_call_wrapper */
    { const uint16_t sp_call = r->sp; JSL(c, 0x528C, 0xC02ACF); GUARD_JSL(c, sp_call, 0x528C); } /* clear_native_menu_sprite_tables_long_wrapper */
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0x5290, 0xC02AD3); GUARD_JSL(c, sp_call, 0x5290); } /* upload_native_menu_sprite_tables_long_wrapper */
    uint8_t db_ret2 = r->db;
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0x5294, 0xC7595C); GUARD_JSL(c, sp_call, 0x5294); } /* upload_native_saved_slot_six_byte_palette */
    uint16_t a_all5 = r->a;
    uint8_t value2 = BUS8(c, 0x307FFF);
    uint8_t a1;
    if (value2 < 4) {
        a1 = value2;
    } else {
        a1 = 0;
    }
    BUS8_SET(c, 0x307FFF, a1);
    BUS8_SET(c, (db_ret2 << 0x10) + 0xA211, a1);
    r->a = (a_all5 >> 8 << 8) | a1;
    r->c = value2 >= 4;
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0x52A9, 0xC757DC); GUARD_JSL(c, sp_call, 0x52A9); } /* highlight_native_saved_slot_rectangle_and_request_publication */
    { const uint16_t sp_call = r->sp; JSL(c, 0x52AD, 0xC02AC7); GUARD_JSL(c, sp_call, 0x52AD); } /* reset_native_menu_publication_long_wrapper */
    RETURN_RTL(c);
}
SOM_REGISTER(0xC75273, SOM_RTL, "gen", construct_native_save_page_after_selecting_active_hero, 0, 0, 1, 1, 0, 60, 20)
