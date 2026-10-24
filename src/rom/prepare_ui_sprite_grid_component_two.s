; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-frame-sprites.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $9B9A
prepare_ui_sprite_grid_component_two:
    rep #$20
    .a16
    lda #$F0F0
    sta $08
    ldy $10
    lda a:$A092,Y
    .i8
    ldx #$02
    sta $00
    txy
    lda $43
    .a16
    and #$000C
    beq prepare_ui_sprite_grid_component_two_c09bba
    lda $F4
    lsr
    lsr
    .a16
    and #$0002
    tay
prepare_ui_sprite_grid_component_two_c09bba:
    lda ($00),Y
    txy
