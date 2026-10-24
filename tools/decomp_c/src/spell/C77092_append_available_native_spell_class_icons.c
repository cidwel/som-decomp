#include "som_c.h"
#include "som_hand_d.h"

/* C77092 append_available_native_spell_class_icons   [class B, 40 bytes, 16 instructions]
 * Source: src/rom/append_available_native_spell_class_icons.s
 * Documented in docs/ui-native-spell-item-icons.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void append_available_native_spell_class_icons(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    RAM8(0xA175) = 0; /* class index */
    a_ldy(r, 0x0008);
    do {
        JSR(c, 0x709A, 0xC76661); /* read_native_spell_class_availability_field */
        REQUIRE_M8(c);
        a_and(r, 0x3F);
        if (!r->z) {
            a_lda(r, RAM8(0xA175));
            a_ldx(r, RAM16(0xA178));
            BUS8_SET(c, r->x, r->a); /* STA $00:0000,X: bank 0, not the data bank */
            i_inx(r);
            RAM16_SET(0xA178, r->x);
            JSR(c, 0x70AF, 0xC770D9); /* append_native_spell_item_sprite_attributes_with_division */
        }
        JSR(c, 0x70B2, 0xC770BA); /* advance_native_two_column_spell_item_icon_positions */
        RAM8(0xA175) = m_inc(r, RAM8(0xA175));
        i_dey(r);
    } while (!r->z);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC77092, SOM_RTS, "hand", append_available_native_spell_class_icons, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 40, 16)
