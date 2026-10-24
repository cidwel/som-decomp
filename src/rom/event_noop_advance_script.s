; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-control.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $E9E7
event_noop_advance_script:
    rep #$20
    inc $D1
    rts
