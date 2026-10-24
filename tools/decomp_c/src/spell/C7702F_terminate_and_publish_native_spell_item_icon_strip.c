#include "som_c.h"
#include "som_hand_d.h"

/* C7702F terminate_and_publish_native_spell_item_icon_strip   [class A, 17 bytes, 6 instructions]
 * Source: src/rom/terminate_and_publish_native_spell_item_icon_strip.s
 * Documented in docs/ui-native-spell-item-icons.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void terminate_and_publish_native_spell_item_icon_strip(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    a_lda(r, 0xFF);
    a_ldx(r, RAM16(0xA178)); /* end of the strip */
    BUS8_SET(c, r->x, r->a); /* STA $00:0000,X: bank 0, not the data bank */
    a_ldx(r, 0x4300);
    JSL(c, 0x703E, 0xC06409); /* jump_native_spell_item_icon_strip_api */
    RETURN_RTS(c);
}
SOM_REGISTER(0xC7702F, SOM_RTS, "hand", terminate_and_publish_native_spell_item_icon_strip, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 17, 6)
