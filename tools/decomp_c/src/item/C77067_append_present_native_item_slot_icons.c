#include "som_c.h"
#include "som_hand_d.h"

/* C77067 append_present_native_item_slot_icons   [class B, 43 bytes, 20 instructions]
 * Source: src/rom/append_present_native_item_slot_icons.s
 * Documented in docs/ui-native-spell-item-icons.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void append_present_native_item_slot_icons(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    a_ldx(r, 0x0008);
    a_ldy(r, 0x0000);
    do {
        a_lda(r, RAM8(0xCC54 + r->y));
        i_inca(r);
        if (!r->z) {
            JSL(c, 0x7076, 0xC06426); /* jump_native_item_slot_description_index_api */
            REQUIRE_M8(c);
            r->c = 0;
            a_adc(r, 0x08);
            i_phx(c);
            a_ldx(r, RAM16(0xA178));
            BUS8_SET(c, r->x, r->a); /* STA $00:0000,X: bank 0, not the data bank */
            i_inx(r);
            RAM16_SET(0xA178, r->x);
            JSR(c, 0x7088, 0xC770D9); /* append_native_spell_item_sprite_attributes_with_division */
            i_plx(c);
        }
        JSR(c, 0x708C, 0xC770BA); /* advance_native_two_column_spell_item_icon_positions */
        i_iny(r);
        i_dex(r);
    } while (!r->z);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC77067, SOM_RTS, "hand", append_present_native_item_slot_icons, 0, L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 43, 20)
