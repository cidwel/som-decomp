; Recovered Secret of Mana USA routine; behaviour documented in docs/event-party-message-queue.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $5BF8
request_native_party_message_resume_script:
    .i16
    ldy #$637F
    sty a:$1D01
    .a8
    lda #$C0
    sta a:$1D03
    stz $9F
    rts
