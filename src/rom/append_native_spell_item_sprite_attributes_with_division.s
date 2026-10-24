; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-spell-item-icons.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $70D9
append_native_spell_item_sprite_attributes_with_division:
    lda a:$A184
    sta f:$004204
    .a8
    lda #$00
    sta f:$004205
    xba
    .a8
    lda #$03
    sta f:$004206
    lda a:$A15B
    asl
    asl
    tax
    lda a:$A15A
    asl
    asl
    asl
    sta a:$9C00,X
    inx
    lda a:$A159
    asl
    asl
    asl
    sta a:$9C00,X
    inx
    rep #$20
    lda f:$004214
    xba
    asl
    .a16
    adc #$0800
    ora a:$A1C7
    sta a:$9C00,X
    inc a:$A1C7
    inc a:$A1C7
    inx
    inx
    sep #$20
    inc a:$A184
    inc a:$A15B
    rts
