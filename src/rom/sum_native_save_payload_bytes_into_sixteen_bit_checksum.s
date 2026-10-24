; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-save-validation.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $5CDC
sum_native_save_payload_bytes_into_sixteen_bit_checksum:
    phx
    rep #$20
    .a16
    lda #$02B8
    sta a:$A171
    stz a:$A173
sum_native_save_payload_bytes_into_sixteen_bit_checksum_c75ce8:
    lda f:$306003,X
    .a16
    and #$00FF
    clc
    adc a:$A173
    sta a:$A173
    inx
    dec a:$A171
    bne sum_native_save_payload_bytes_into_sixteen_bit_checksum_c75ce8
    sep #$20
    plx
    rts
