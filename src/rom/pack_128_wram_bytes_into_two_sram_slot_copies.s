; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-save-write.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $56E1
pack_128_wram_bytes_into_two_sram_slot_copies:
    .a8
    lda #$80
pack_128_wram_bytes_into_two_sram_slot_copies_c756e3:
    xba
    lda a:$0000,Y
    sta f:$306000,X
    sta f:$307000,X
    inx
    iny
    xba
    dec
    bne pack_128_wram_bytes_into_two_sram_slot_copies_c756e3
    rts
