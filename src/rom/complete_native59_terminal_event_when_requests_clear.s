; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native59-actions.md.
.setcpu "65816"
.smart
.a8
.i16

mark_controller_and_request_numeric_boss_death_event = $0C11

.segment "CODE"
.org $885F
complete_native59_terminal_event_when_requests_clear:
    lda a:$00D9
    ora a:$00DA
    ora a:$00DB
    .a16
    bit #$0080
    bne complete_native59_terminal_event_when_requests_clear_c28881
    lda a:$1D04
    .a16
    bit #$0020
    bne complete_native59_terminal_event_when_requests_clear_c28881
    ldx $87
    lda a:$0072,X
    beq complete_native59_terminal_event_when_requests_clear_c2887f
    jsr mark_controller_and_request_numeric_boss_death_event
complete_native59_terminal_event_when_requests_clear_c2887f:
    sec
    rts
complete_native59_terminal_event_when_requests_clear_c28881:
    clc
    rts
