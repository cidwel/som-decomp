; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-spell-item-icons.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $70BA
advance_native_two_column_spell_item_icon_positions:
    .a8
    lda #$11
    sta a:$A15A
    lda a:$A185
    .a8
    bit #$01
    beq advance_native_two_column_spell_item_icon_positions_c770d5
    .a8
    lda #$01
    sta a:$A15A
    lda a:$A159
    inc
    inc
    inc
    inc
    sta a:$A159
advance_native_two_column_spell_item_icon_positions_c770d5:
    inc a:$A185
    rts
