; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-controller-layout.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6FB7
restore_native_controller_bindings_and_copy_mirror_free_runtime_flags:
    .i16
    ldx #$0003
restore_native_controller_bindings_and_copy_mirror_free_runtime_flags_c76fba:
    lda a:$A236,X
    sta $ED,X
    dex
    bne restore_native_controller_bindings_and_copy_mirror_free_runtime_flags_c76fba
    .i16
    ldx #$0003
restore_native_controller_bindings_and_copy_mirror_free_runtime_flags_c76fc5:
    lda $ED,X
    sta a:$A22E,X
    sta a:$A236,X
    .a8
    and #$03
    sta $ED,X
    dex
    bne restore_native_controller_bindings_and_copy_mirror_free_runtime_flags_c76fc5
    rtl
