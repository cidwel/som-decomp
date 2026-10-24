; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-mode7-transition.md.
.setcpu "65816"
.smart
.a8
.i16

run_complete_three_phase_mode_seven_transition = $4028

.segment "CODE"
.org $4000
preserve_direct_page_and_run_complete_mode_seven_transition:
    php
    phb
    rep #$30
    .i16
    ldx #$0020
    .i16
    ldy #$1040
    .a16
    lda #$002F
    mvn #$00, #$00
    sep #$20
    jsr run_complete_three_phase_mode_seven_transition
    rep #$20
    .i16
    ldx #$1040
    .i16
    ldy #$0020
    .a16
    lda #$002F
    mvn #$00, #$00
    sep #$20
    plb
    plp
    rtl
