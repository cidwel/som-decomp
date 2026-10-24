; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-controller-layout.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6F15
compare_four_native_controller_permutation_entries:
    .a8
    lda #$04
    .i16
    ldx #$0000
compare_four_native_controller_permutation_entries_c76f1a:
    xba
    lda a:$9C00,X
    cmp a:$9C04,X
    bne compare_four_native_controller_permutation_entries_c76f28
    inx
    xba
    dec
    bne compare_four_native_controller_permutation_entries_c76f1a
compare_four_native_controller_permutation_entries_c76f28:
    rts
