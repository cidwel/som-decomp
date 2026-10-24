; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-composition.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $F0E9
event_reserved_3d_stall:
    rts
