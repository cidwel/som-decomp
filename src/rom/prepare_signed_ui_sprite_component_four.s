; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-frame-sprites.md.
.setcpu "65816"
.smart
.a8
.i16

position_signed_ui_sprite_component = $9FFF

.segment "CODE"
.org $9F81
prepare_signed_ui_sprite_component_four:
    rep #$20
    .a16
    lda #$0CFC
    ldx $5F
    .i8
    cpx #$04
    bne prepare_signed_ui_sprite_component_four_c09f91
    .a16
    lda #$ECFC
    bra prepare_signed_ui_sprite_component_four_c09f9b
prepare_signed_ui_sprite_component_four_c09f91:
    ldx $7A
    beq prepare_signed_ui_sprite_component_four_c09f9b
    bmi prepare_signed_ui_sprite_component_four_c09f9a
    inc
    bra prepare_signed_ui_sprite_component_four_c09f9b
prepare_signed_ui_sprite_component_four_c09f9a:
    dec
prepare_signed_ui_sprite_component_four_c09f9b:
    sta $08
    ldy $10
    lda a:$A2DE,Y
    .i8
    ldy #$04
    bra position_signed_ui_sprite_component
