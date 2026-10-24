; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-frame-sprites.md.
.setcpu "65816"
.smart
.a8
.i16

position_ui_sprite_grid_component = $9BBD

.segment "CODE"
.org $9BEE
prepare_ui_sprite_grid_component_five:
    rep #$20
    ldy $10
    lda a:$A0AA,Y
    sta $00
    ldx a:$0A45
    lda a:$9C1B,X
    asl
    .a16
    and #$0007
    tay
    .a16
    lda #$F4FC
    .i8
    cpy #$00
    beq prepare_ui_sprite_grid_component_five_c09c13
    .a16
    lda #$FCFC
    .i8
    cpy #$02
    beq prepare_ui_sprite_grid_component_five_c09c13
    .a16
    lda #$FCFC
prepare_ui_sprite_grid_component_five_c09c13:
    sta $08
    lda ($00),Y
    .i8
    ldy #$05
    bra position_ui_sprite_grid_component
