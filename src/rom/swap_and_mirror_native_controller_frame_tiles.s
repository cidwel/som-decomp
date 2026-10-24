; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-controller-layout.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6F74
swap_and_mirror_native_controller_frame_tiles:
    .i16
    ldx #$006C
    .i16
    ldy #$00B0
    rep #$20
    .a16
    lda #$0003
    sta a:$A171
swap_and_mirror_native_controller_frame_tiles_c76f82:
    lda a:$9000,X
    pha
    lda a:$9000,Y
    .a16
    eor #$C000
    sta a:$9000,X
    pla
    .a16
    eor #$C000
    sta a:$9000,Y
    inx
    inx
    dey
    dey
    dec a:$A171
    bne swap_and_mirror_native_controller_frame_tiles_c76f82
    sep #$20
    .a8
    lda #$02
    tsb a:$A20A
    rtl
