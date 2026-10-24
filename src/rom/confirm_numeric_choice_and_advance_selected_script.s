; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-numeric-selection.md.
.setcpu "65816"
.smart
.a8
.i16

preserve_accumulator_byte_and_request_fixed_local_audio_presets = $1BA5

.segment "CODE"
.org $1ACF
confirm_numeric_choice_and_advance_selected_script:
    bne confirm_numeric_choice_and_advance_selected_script_c01af0
    pha
    rep #$20
    lda a:$A200
    .a16
    and #$00FF
    inc
    asl
    clc
    adc a:$A1D5
    sta a:$A1D5
    sta f:$001D01
    sep #$20
    inc a:$A160
    jsr preserve_accumulator_byte_and_request_fixed_local_audio_presets
    pla
confirm_numeric_choice_and_advance_selected_script_c01af0:
    rts
