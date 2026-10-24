; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-controller-layout.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6E36
publish_four_native_controller_button_label_tile_strips:
    rep #$20
    .a16
    lda #$0000
    sta a:$A171
publish_four_native_controller_button_label_tile_strips_c76e3e:
    lda a:$A171
    asl
    asl
    tax
    lda a:$A1E0,X
    clc
    .a16
    adc #$0042
    pha
    lda a:$A171
    tax
    lda a:$9C00,X
    .a16
    and #$00FF
    asl
    tax
    lda f:$C76FE1,X
    .i16
    ldy #$0007
    plx
    pha
    lda a:$9000,X
    .a16
    and #$1C00
    sta a:$A173
    pla
    ora a:$A173
publish_four_native_controller_button_label_tile_strips_c76e6e:
    sta a:$9000,X
    inc
    inc
    sta a:$9040,X
    inc
    inc
    inx
    inx
    dey
    bne publish_four_native_controller_button_label_tile_strips_c76e6e
    inc a:$A171
    .a16
    lda #$0004
    cmp a:$A171
    bne publish_four_native_controller_button_label_tile_strips_c76e3e
    sep #$20
    rts
