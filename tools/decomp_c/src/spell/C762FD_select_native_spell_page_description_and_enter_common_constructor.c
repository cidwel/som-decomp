#include "som_c.h"

/* C762FD select_native_spell_page_description_and_enter_common_constructor   [class B, 63 bytes, 22 instructions]
 * Source: src/rom/select_native_spell_page_description_and_enter_common_constructor.s
 * Documented in docs/ui-native-spell-item-page.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: nothing.
 */
/* The page constructor body starting at C7:6309, shared by the two entries below (C762FD stores 6 in $A20F and branches here, C76304 stores 5 and falls into it). */
static void spell_page_common_constructor(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    { const uint16_t sp_call = r->sp; JSL(c, 0x630C, 0xC02ACB); GUARD_JSL_DB(c, sp_call, 0x630C, 0x7E); } /* construct_native_menu_page_long_call_wrapper */
    { const uint16_t sp_call = r->sp; JSL(c, 0x6310, 0xC029A5); GUARD_JSL_DB(c, sp_call, 0x6310, 0x7E); } /* render_native_selected_actor_page_caption */
    { const uint16_t sp_call = r->sp; JSL(c, 0x6314, 0xC02ACF); GUARD_JSL_DB(c, sp_call, 0x6314, 0x7E); } /* clear_native_menu_sprite_tables_long_wrapper */
    { const uint16_t sp_call = r->sp; JSL(c, 0x6318, 0xC7595C); GUARD_JSL_DB(c, sp_call, 0x6318, 0x7E); } /* upload_native_saved_slot_six_byte_palette */
    if (!r->mf) { c->fail = 3; return; }   /* the code below is assembled for an 8-bit accumulator */
    a_lda(r, RAM8(0xA20F));
    a_cmp(r, 0x05);
    if (r->z) {
        { const uint16_t sp_call = r->sp; JSR(c, 0x632A, 0xC77019); GUARD_JSR_DB(c, sp_call, 0x632A, 0x7E); } /* construct_native_item_slot_icon_strip */
        { const uint16_t sp_call = r->sp; JSR(c, 0x632D, 0xC765B4); GUARD_JSR_DB(c, sp_call, 0x632D, 0x7E); } /* render_eight_native_item_slot_labels_and_percentages */
    } else {
        { const uint16_t sp_call = r->sp; JSR(c, 0x6322, 0xC77001); GUARD_JSR_DB(c, sp_call, 0x6322, 0x7E); } /* construct_native_spell_class_icon_strip */
        { const uint16_t sp_call = r->sp; JSR(c, 0x6325, 0xC76549); GUARD_JSR_DB(c, sp_call, 0x6325, 0x7E); } /* render_eight_native_spell_class_labels_and_decimal_fields */
    }
    { const uint16_t sp_call = r->sp; JSL(c, 0x6331, 0xC02AE3); GUARD_JSL_DB(c, sp_call, 0x6331, 0x7E); } /* reset_and_rebuild_native_menu_frame_without_heading */
    { const uint16_t sp_call = r->sp; JSL(c, 0x6335, 0xC02AC7); GUARD_JSL_DB(c, sp_call, 0x6335, 0x7E); } /* reset_native_menu_publication_long_wrapper */
    if (!r->mf) { c->fail = 3; return; }
    a_lda(r, 0x08);
    RAM8(0xA212) = m_trb(r, RAM8(0xA212));
    RETURN_RTL(c);
}

static void select_native_spell_page_description_and_enter_common_constructor(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, -1)) return;
    a_lda(r, 0x06);
    RAM8(0xA20F) = r->a;
    spell_page_common_constructor(c);
}
SOM_REGISTER(0xC762FD, SOM_RTL, "hand", select_native_spell_page_description_and_enter_common_constructor, 0, 0, 1, 1, 0, 63, 22)

/* Interior entry C7:6304 (construct_native_spell_or_item_page_from_selected_description), catalogued inside this routine: same body, $A20F = 5. */
static void construct_native_spell_or_item_page_from_selected_description(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, -1)) return;
    a_lda(r, 0x05);
    RAM8(0xA20F) = r->a;
    spell_page_common_constructor(c);
}
SOM_REGISTER(0xC76304, SOM_RTL, "hand", construct_native_spell_or_item_page_from_selected_description, 0, 0, 1, 1, 0, 56, 20)
