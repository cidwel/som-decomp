; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-save-validation.md.
.setcpu "65816"
.smart
.a8
.i16

sum_native_save_payload_bytes_into_sixteen_bit_checksum = $5CDC

.segment "CODE"
.org $5C3B
test_two_native_save_checksums_and_rotate_invalid_mask:
    .a8
    lda #$02
test_two_native_save_checksums_and_rotate_invalid_mask_c75c3d:
    pha
    ror a:$A216
    bcs test_two_native_save_checksums_and_rotate_invalid_mask_c75c5b
    jsr sum_native_save_payload_bytes_into_sixteen_bit_checksum
    lda a:$A173
    cmp f:$306001,X
    bne test_two_native_save_checksums_and_rotate_invalid_mask_c75c5b
    lda a:$A174
    cmp f:$306002,X
    bne test_two_native_save_checksums_and_rotate_invalid_mask_c75c5b
    clc
    bra test_two_native_save_checksums_and_rotate_invalid_mask_c75c61
test_two_native_save_checksums_and_rotate_invalid_mask_c75c5b:
    sec
    ror a:$A215
    bra test_two_native_save_checksums_and_rotate_invalid_mask_c75c65
test_two_native_save_checksums_and_rotate_invalid_mask_c75c61:
    clc
    ror a:$A215
test_two_native_save_checksums_and_rotate_invalid_mask_c75c65:
    rep #$20
    txa
    clc
    .a16
    adc #$1000
    tax
    sep #$20
    pla
    dec
    bne test_two_native_save_checksums_and_rotate_invalid_mask_c75c3d
    rts
