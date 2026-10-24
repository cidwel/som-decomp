; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-frame-sprites.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $9FD3
prepare_signed_ui_sprite_component_two:
    rep #$20
    .a16
    lda #$FCF0
    ldx $5F
    .i8
    cpx #$04
    bne prepare_signed_ui_sprite_component_two_c09fe1
    .a16
    lda #$F4F0
prepare_signed_ui_sprite_component_two_c09fe1:
    sta $08
    ldy $10
    lda a:$A2CE,Y
    .i8
    ldx #$02
    sta $00
    txy
    lda $43
    .a16
    and #$000C
    beq prepare_signed_ui_sprite_component_two_c09ffc
    lda $F4
    lsr
    lsr
    .a16
    and #$0002
    tay
prepare_signed_ui_sprite_component_two_c09ffc:
    lda ($00),Y
    txy
