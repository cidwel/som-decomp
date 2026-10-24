; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-composition.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $F1CE
event_reserved_47_stall:
    rts
