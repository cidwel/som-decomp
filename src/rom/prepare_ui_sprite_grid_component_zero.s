; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-frame-sprites.md.
.setcpu "65816"
.smart
.a8
.i16

position_ui_sprite_grid_component = $9BBD

.segment "CODE"
.org $9B4B
prepare_ui_sprite_grid_component_zero:
    rep #$20
    .a16
    lda #$F0F4
    sta $08
    ldy $10
    lda a:$A082,Y
    .i8
    ldy #$00
    bra position_ui_sprite_grid_component
