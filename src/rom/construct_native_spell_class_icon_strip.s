; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-spell-item-icons.md.
.setcpu "65816"
.smart
.a8
.i16

append_available_native_spell_class_icons = $7092
initialize_native_spell_item_icon_descriptor_cursor = $7040
terminate_and_publish_native_spell_item_icon_strip = $702F
upload_native_menu_sprite_tables_long_wrapper = $C02AD3

.segment "CODE"
.org $7001
construct_native_spell_class_icon_strip:
    jsr initialize_native_spell_item_icon_descriptor_cursor
    .a8
    lda #$AA
    sta a:$9E00
    .a8
    lda #$2A
    sta a:$9E01
    jsr append_available_native_spell_class_icons
    jsr terminate_and_publish_native_spell_item_icon_strip
    jsl f:upload_native_menu_sprite_tables_long_wrapper
    rts
