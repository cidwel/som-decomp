; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-save-load.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $588B
unpack_128_save_nibble_pairs_into_wram:
    .a8
    lda #$80
unpack_128_save_nibble_pairs_into_wram_c7588d:
    xba
    lda f:$306000,X
    pha
    lsr
    lsr
    lsr
    lsr
    sta a:$0000,Y
    iny
    pla
    .a8
    and #$0F
    sta a:$0000,Y
    iny
    inx
    xba
    dec
    bne unpack_128_save_nibble_pairs_into_wram_c7588d
    rts
