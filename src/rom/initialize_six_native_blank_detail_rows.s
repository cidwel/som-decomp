; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-spell-item-detail.md.
.setcpu "65816"
.smart
.a8
.i16

append_native_saved_slot_text_line_token = $538D

.segment "CODE"
.org $6BCF
initialize_six_native_blank_detail_rows:
    .i16
    ldx #$0000
    .a8
    lda #$06
initialize_six_native_blank_detail_rows_c76bd4:
    xba
    jsr append_native_saved_slot_text_line_token
    xba
    dec
    bne initialize_six_native_blank_detail_rows_c76bd4
    rts
