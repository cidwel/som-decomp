; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-wait-flag-decrement.md.
.setcpu "65816"
.smart
.a8
.i16

dispatch_native_event_opcode_or_wait_state = $E8D3

.segment "CODE"
.org $EC7F
event_decrement_flag_nibble_and_resume_dispatch:
    ldx $05
    lda a:$CF00,X
    .a8
    and #$0F
    dec
    bpl event_decrement_flag_nibble_and_resume_dispatch_c1ec8b
    .a8
    lda #$00
event_decrement_flag_nibble_and_resume_dispatch_c1ec8b:
    sta $00
    lda a:$CF00,X
    .a8
    and #$F0
    ora $00
    sta a:$CF00,X
    rep #$20
    inc $D1
    inc $D1
    brl dispatch_native_event_opcode_or_wait_state
