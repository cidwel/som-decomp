#include "som_c.h"

/* C77019 construct_native_item_slot_icon_strip   [class B, 22 bytes, 8 instructions]
 * Source: src/rom/construct_native_item_slot_icon_strip.s
 * Documented in docs/ui-native-spell-item-icons.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BYCV.
 */
static void construct_native_item_slot_icon_strip(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0x701B, 0xC77040); /* initialize_native_spell_item_icon_descriptor_cursor */
    uint16_t a_all = r->a;
    RAM8(0x9E00) = 0xAA;
    RAM8(0x9E01) = 0xAA;
    r->a = (a_all >> 8 << 8) | 0xAA;
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x7026, 0xC77067); /* append_present_native_item_slot_icons */
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x7029, 0xC7702F); /* terminate_and_publish_native_spell_item_icon_strip */
    r->mf = 1;
    r->xf = 0;
    JSL(c, 0x702D, 0xC02AD3); /* upload_native_menu_sprite_tables_long_wrapper */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC77019, SOM_RTS, "gen", construct_native_item_slot_icon_strip, 0, L_B | L_Y | L_C | L_V, 1, 1, 0, 22, 8)
