; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-spell-item-icons.md.
.setcpu "65816"
.smart
.a8
.i16

advance_native_two_column_spell_item_icon_positions = $70BA
append_native_spell_item_sprite_attributes_with_division = $70D9
read_native_spell_class_availability_field = $6661

.segment "CODE"
.org $7092
append_available_native_spell_class_icons:
    stz a:$A175
    .i16
    ldy #$0008
append_available_native_spell_class_icons_c77098:
    jsr read_native_spell_class_availability_field
    .a8
    and #$3F
    beq append_available_native_spell_class_icons_c770b0
    lda a:$A175
    ldx a:$A178
    sta f:$000000,X
    inx
    stx a:$A178
    jsr append_native_spell_item_sprite_attributes_with_division
append_available_native_spell_class_icons_c770b0:
    jsr advance_native_two_column_spell_item_icon_positions
    inc a:$A175
    dey
    bne append_available_native_spell_class_icons_c77098
    rts
