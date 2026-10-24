; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-save-validation.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $5C04
test_native_save_signature_pair_and_rotate_invalid_mask:
    lda f:$306000,X
    .a8
    cmp #$C5
    bne test_native_save_signature_pair_and_rotate_invalid_mask_c75c14
    lda f:$3062BB,X
    .a8
    cmp #$3A
    beq test_native_save_signature_pair_and_rotate_invalid_mask_c75c1a
test_native_save_signature_pair_and_rotate_invalid_mask_c75c14:
    sec
    ror a:$A216
    bra test_native_save_signature_pair_and_rotate_invalid_mask_c75c1e
test_native_save_signature_pair_and_rotate_invalid_mask_c75c1a:
    clc
    ror a:$A216
test_native_save_signature_pair_and_rotate_invalid_mask_c75c1e:
    rts
