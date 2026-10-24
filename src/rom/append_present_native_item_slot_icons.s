; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-spell-item-icons.md.
.setcpu "65816"
.smart
.a8
.i16

advance_native_two_column_spell_item_icon_positions = $70BA
append_native_spell_item_sprite_attributes_with_division = $70D9
jump_native_item_slot_description_index_api = $C06426

.segment "CODE"
.org $7067
append_present_native_item_slot_icons:
    .i16
    ldx #$0008
    .i16
    ldy #$0000
append_present_native_item_slot_icons_c7706d:
    lda a:$CC54,Y
    inc
    beq append_present_native_item_slot_icons_c7708a
    jsl f:jump_native_item_slot_description_index_api
    clc
    .a8
    adc #$08
    phx
    ldx a:$A178
    sta f:$000000,X
    inx
    stx a:$A178
    jsr append_native_spell_item_sprite_attributes_with_division
    plx
append_present_native_item_slot_icons_c7708a:
    jsr advance_native_two_column_spell_item_icon_positions
    iny
    dex
    bne append_present_native_item_slot_icons_c7706d
    rts
