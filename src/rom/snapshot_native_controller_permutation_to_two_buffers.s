; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-controller-layout.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6F29
snapshot_native_controller_permutation_to_two_buffers:
    .i16
    ldx #$0004
snapshot_native_controller_permutation_to_two_buffers_c76f2c:
    lda a:$9BFF,X
    sta a:$9C03,X
    sta a:$9C07,X
    dex
    bne snapshot_native_controller_permutation_to_two_buffers_c76f2c
    rtl
