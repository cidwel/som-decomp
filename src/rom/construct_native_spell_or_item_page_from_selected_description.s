; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-spell-item-page.md.
.setcpu "65816"
.smart
.a8
.i16

clear_native_menu_sprite_tables_long_wrapper = $C02ACF
construct_native_item_slot_icon_strip = $7019
construct_native_menu_page_long_call_wrapper = $C02ACB
construct_native_spell_class_icon_strip = $7001
render_eight_native_item_slot_labels_and_percentages = $65B4
render_eight_native_spell_class_labels_and_decimal_fields = $6549
render_native_selected_actor_page_caption = $C029A5
reset_and_rebuild_native_menu_frame_without_heading = $C02AE3
reset_native_menu_publication_long_wrapper = $C02AC7
upload_native_saved_slot_six_byte_palette = $C7595C

.segment "CODE"
.org $6304
construct_native_spell_or_item_page_from_selected_description:
    .a8
    lda #$05
    sta a:$A20F
    jsl f:construct_native_menu_page_long_call_wrapper
    jsl f:render_native_selected_actor_page_caption
    jsl f:clear_native_menu_sprite_tables_long_wrapper
    jsl f:upload_native_saved_slot_six_byte_palette
    lda a:$A20F
    .a8
    cmp #$05
    beq construct_native_spell_or_item_page_from_selected_description_c76328
    jsr construct_native_spell_class_icon_strip
    jsr render_eight_native_spell_class_labels_and_decimal_fields
    bra construct_native_spell_or_item_page_from_selected_description_c7632e
construct_native_spell_or_item_page_from_selected_description_c76328:
    jsr construct_native_item_slot_icon_strip
    jsr render_eight_native_item_slot_labels_and_percentages
construct_native_spell_or_item_page_from_selected_description_c7632e:
    jsl f:reset_and_rebuild_native_menu_frame_without_heading
    jsl f:reset_native_menu_publication_long_wrapper
    .a8
    lda #$08
    trb a:$A212
    rtl
