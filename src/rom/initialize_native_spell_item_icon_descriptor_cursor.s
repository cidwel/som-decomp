; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-spell-item-icons.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $7040
initialize_native_spell_item_icon_descriptor_cursor:
    .a8
    lda #$04
    sta a:$A159
    .a8
    lda #$01
    sta a:$A15A
    .a8
    lda #$00
    sta a:$A15B
    stz a:$A185
    stz a:$A184
    rep #$20
    lda f:$C0640C
    sta a:$A178
    sep #$20
    .i16
    ldx #$3030
    stx a:$A1C7
    rts
