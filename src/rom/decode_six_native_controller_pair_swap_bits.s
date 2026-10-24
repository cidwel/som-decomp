; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-controller-layout.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6F39
decode_six_native_controller_pair_swap_bits:
    xba
    .i16
    ldy #$0000
    .a8
    lda #$00
    xba
decode_six_native_controller_pair_swap_bits_c76f40:
    lsr
    bcc decode_six_native_controller_pair_swap_bits_c76f62
    pha
    phy
    tya
    asl
    tax
    lda f:$C76FD5,X
    tay
    lda f:$C76FD6,X
    tax
    lda a:$9C00,X
    pha
    lda a:$9C00,Y
    sta a:$9C00,X
    pla
    sta a:$9C00,Y
    ply
    pla
decode_six_native_controller_pair_swap_bits_c76f62:
    iny
    .i16
    cpy #$0007
    bne decode_six_native_controller_pair_swap_bits_c76f40
    rts
