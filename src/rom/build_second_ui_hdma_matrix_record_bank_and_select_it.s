; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-frame-hdma.md.
.setcpu "65816"
.smart
.a8
.i16

build_second_ui_hdma_matrix_record_bank = $91CF

.segment "CODE"
.org $91C7
build_second_ui_hdma_matrix_record_bank_and_select_it:
    jsr build_second_ui_hdma_matrix_record_bank
    .i8
    ldx #$84
    stx $60
    rts
