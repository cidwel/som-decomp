; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-save-write.md.
.setcpu "65816"
.smart
.a8
.i16

sum_native_save_payload_bytes_into_sixteen_bit_checksum = $5CDC

.segment "CODE"
.org $56A9
write_two_save_signatures_and_checksum_primary_payload:
    .a8
    lda #$C5
    sta f:$306000,X
    sta f:$307000,X
    .a8
    lda #$3A
    sta f:$3062BB,X
    sta f:$3072BB,X
    jsr sum_native_save_payload_bytes_into_sixteen_bit_checksum
    rep #$20
    lda a:$A173
    sta f:$306001,X
    sta f:$307001,X
    sep #$20
    rts
