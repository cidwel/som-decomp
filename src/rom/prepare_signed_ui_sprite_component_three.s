; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-frame-sprites.md.
.setcpu "65816"
.smart
.a8
.i16

position_signed_ui_sprite_component = $9FFF

.segment "CODE"
.org $9F68
prepare_signed_ui_sprite_component_three:
    rep #$20
    .a16
    lda #$08FC
    ldx $5F
    .i8
    cpx #$04
    bne prepare_signed_ui_sprite_component_three_c09f76
    .a16
    lda #$F0FC
prepare_signed_ui_sprite_component_three_c09f76:
    sta $08
    ldy $10
    lda a:$A2D6,Y
    .i8
    ldy #$03
    bra position_signed_ui_sprite_component
