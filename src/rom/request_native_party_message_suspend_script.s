; Recovered Secret of Mana USA routine; behaviour documented in docs/event-party-message-queue.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $5BEA
request_native_party_message_suspend_script:
    .i16
    ldy #$637D
    sty a:$1D01
    .a8
    lda #$C0
    sta a:$1D03
    stz $A3
    rts
