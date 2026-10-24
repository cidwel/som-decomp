; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-render-core.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $0D7F
request_dialogue_window_transfer_of_256_bytes:
    rep #$20
    .a16
    lda #$0100
    sta f:$001D08
    sep #$20
    rts
