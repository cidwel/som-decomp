; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-ten-terminal.md.
.setcpu "65816"
.smart
.a8
.i16

mark_controller_and_request_numeric_boss_death_event = $0C11

.segment "CODE"
.org $7AD0
finish_descriptor_ten_terminal_when_controllers_unlock_and_event_nonzero:
    ldx $87
    lda a:$00D9
    ora a:$00DA
    ora a:$00DB
    .a16
    bit #$0080
    bne finish_descriptor_ten_terminal_when_controllers_unlock_and_event_nonzero_c27af2
    lda a:$1D04
    .a16
    bit #$0020
    bne finish_descriptor_ten_terminal_when_controllers_unlock_and_event_nonzero_c27af2
    lda a:$0072,X
    beq finish_descriptor_ten_terminal_when_controllers_unlock_and_event_nonzero_c27af2
    jsr mark_controller_and_request_numeric_boss_death_event
    sec
    rts
finish_descriptor_ten_terminal_when_controllers_unlock_and_event_nonzero_c27af2:
    clc
    rts
