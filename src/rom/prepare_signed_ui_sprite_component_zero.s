; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-frame-sprites.md.
.setcpu "65816"
.smart
.a8
.i16

position_signed_ui_sprite_component = $9FFF

.segment "CODE"
.org $9F4E
prepare_signed_ui_sprite_component_zero:
    rep #$20
    .a16
    lda #$E0F8
    ldx $5F
    .i8
    cpx #$04
    bne prepare_signed_ui_sprite_component_zero_c09f5c
    .a16
    lda #$08F8
prepare_signed_ui_sprite_component_zero_c09f5c:
    sta $08
    ldy $10
    lda a:$A2BE,Y
    .i8
    ldy #$00
    brl position_signed_ui_sprite_component
