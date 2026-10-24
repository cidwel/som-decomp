; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-save-write.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $57B1
pack_six_party_name_bytes_into_two_slot_copies:
    .a8
    lda #$06
pack_six_party_name_bytes_into_two_slot_copies_c757b3:
    xba
    lda a:$0000,Y
    sta f:$306000,X
    sta f:$307000,X
    iny
    inx
    xba
    dec
    bne pack_six_party_name_bytes_into_two_slot_copies_c757b3
    rts
