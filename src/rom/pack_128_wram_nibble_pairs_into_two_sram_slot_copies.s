; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-save-write.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $56F6
pack_128_wram_nibble_pairs_into_two_sram_slot_copies:
    .a8
    lda #$80
    sta a:$A175
pack_128_wram_nibble_pairs_into_two_sram_slot_copies_c756fb:
    lda a:$0000,Y
    asl
    asl
    asl
    asl
    sta a:$A1CB
    lda a:$0001,Y
    .a8
    and #$0F
    ora a:$A1CB
    sta f:$306000,X
    sta f:$307000,X
    iny
    iny
    inx
    dec a:$A175
    bne pack_128_wram_nibble_pairs_into_two_sram_slot_copies_c756fb
    rts
