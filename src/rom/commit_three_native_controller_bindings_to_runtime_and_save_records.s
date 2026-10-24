; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-settings-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6FA7
commit_three_native_controller_bindings_to_runtime_and_save_records:
    .i16
    ldx #$0003
commit_three_native_controller_bindings_to_runtime_and_save_records_c76faa:
    lda a:$A22E,X
    sta $ED,X
    sta f:$7ECC6C,X
    dex
    bne commit_three_native_controller_bindings_to_runtime_and_save_records_c76faa
    rtl
