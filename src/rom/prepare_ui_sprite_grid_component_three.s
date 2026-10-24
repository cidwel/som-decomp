; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-frame-sprites.md.
.setcpu "65816"
.smart
.a8
.i16

position_ui_sprite_grid_component = $9BBD

.segment "CODE"
.org $9B5B
prepare_ui_sprite_grid_component_three:
    rep #$20
    .a16
    lda #$F8F8
    sta $08
    ldy $10
    lda a:$A09A,Y
    .i8
    ldy #$03
    bra position_ui_sprite_grid_component
