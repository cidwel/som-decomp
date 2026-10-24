; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-control.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $EA4E
event_release_party_freeze:
    lda $F1
    .a8
    and #$7F
    sta $F1
    rep #$20
    inc $D1
    rts
