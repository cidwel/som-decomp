; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-frame-radial.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $8FF3
advance_ui_attribute_sample_cursor_and_copy_native_buffer_byte:
    rep #$20
    lda $8A
    clc
    .a16
    adc #$002D
    .a16
    and #$03FF
    sta $8A
    tax
    sep #$20
    lda a:$E800,X
    sta a:$EC00,X
    rts
