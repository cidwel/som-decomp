; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-map-transition-commands.md.
.setcpu "65816"
.smart
.a8
.i16

accept_numeric_event_request = $E77B

.segment "CODE"
.org $EB2F
event_request_fade_operand_and_update_transition_flag:
    rep #$20
    inc $D1
    inc $D1
    sep #$20
    lda $E3
    .a8
    and #$F0
    bit $05
    bvc event_request_fade_operand_and_update_transition_flag_c1eb41
    .a8
    ora #$01
event_request_fade_operand_and_update_transition_flag_c1eb41:
    sta $E3
    rep #$20
    lda $05
    .a16
    and #$003F
    .a16
    ora #$0D00
    brl accept_numeric_event_request
