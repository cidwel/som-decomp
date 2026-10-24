#include "som_c.h"

/* C77001 construct_native_spell_class_icon_strip   [class B, 24 bytes, 9 instructions]
 * Source: src/rom/construct_native_spell_class_icon_strip.s
 * Documented in docs/ui-native-spell-item-icons.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BYCV.
 */
static void construct_native_spell_class_icon_strip(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0x7003, 0xC77040); /* initialize_native_spell_item_icon_descriptor_cursor */
    uint16_t a_all = r->a;
    RAM8(0x9E00) = 0xAA;
    RAM8(0x9E01) = 0x2A;
    r->a = (a_all >> 8 << 8) | 0x2A;
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x7010, 0xC77092); /* append_available_native_spell_class_icons */
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x7013, 0xC7702F); /* terminate_and_publish_native_spell_item_icon_strip */
    r->mf = 1;
    r->xf = 0;
    JSL(c, 0x7017, 0xC02AD3); /* upload_native_menu_sprite_tables_long_wrapper */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC77001, SOM_RTS, "gen", construct_native_spell_class_icon_strip, 0, L_B | L_Y | L_C | L_V, 1, 1, 0, 24, 9)
