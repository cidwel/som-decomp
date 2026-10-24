; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-party-status-page.md.
.setcpu "65816"
.smart
.a8
.i16

append_native_saved_slot_text_line_token = $538D

.segment "CODE"
.org $6986
append_native_party_status_count_glyph_and_newline:
    clc
    .a8
    adc #$B5
    sta a:$9C01,X
    .a8
    lda #$80
    sta a:$9C00,X
    inx
    inx
    jsr append_native_saved_slot_text_line_token
    rts
