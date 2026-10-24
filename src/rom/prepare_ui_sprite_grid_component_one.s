; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-frame-sprites.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c09bb6 = $9BB6

.segment "CODE"
.org $9B7B
prepare_ui_sprite_grid_component_one:
    rep #$20
    .a16
    lda #$F6F0
    ldx $5F
    .i8
    cpx #$04
    bne prepare_ui_sprite_grid_component_one_c09b89
    .a16
    lda #$F0F0
prepare_ui_sprite_grid_component_one_c09b89:
    sta $08
    ldy $10
    lda a:$A08A,Y
    .i8
    ldx #$01
    sta $00
    lda $F4
    lsr
    lsr
    bra routine_c09bb6
