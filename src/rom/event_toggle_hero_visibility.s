; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-control.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $EA26
event_toggle_hero_visibility:
    lda a:$E00E
    .a8
    eor #$80
    sta a:$E00E
    lda a:$E20E
    .a8
    eor #$80
    sta a:$E20E
    lda a:$E40E
    .a8
    eor #$80
    sta a:$E40E
    rep #$20
    inc $D1
    rts
