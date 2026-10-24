; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-control.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $EA59
event_yield_until_all_actors_idle:
    .a8
    lda #$85
    sta $D0
    rep #$20
    inc $D1
    rts
