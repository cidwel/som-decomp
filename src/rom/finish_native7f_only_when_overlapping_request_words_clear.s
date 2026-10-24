; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native7f-terminal.md.
.setcpu "65816"
.smart
.a8
.i16

mark_controller_and_request_numeric_boss_death_event = $0C11

.segment "CODE"
.org $977B
finish_native7f_only_when_overlapping_request_words_clear:
    lda a:$00D9
    ora a:$00DA
    ora a:$00DB
    .a16
    bit #$0080
    bne finish_native7f_only_when_overlapping_request_words_clear_c2979d
    lda a:$1D04
    .a16
    bit #$0020
    bne finish_native7f_only_when_overlapping_request_words_clear_c2979d
    ldx $87
    lda a:$0072,X
    beq finish_native7f_only_when_overlapping_request_words_clear_c2979b
    jsr mark_controller_and_request_numeric_boss_death_event
finish_native7f_only_when_overlapping_request_words_clear_c2979b:
    sec
    rts
finish_native7f_only_when_overlapping_request_words_clear_c2979d:
    clc
    rts
