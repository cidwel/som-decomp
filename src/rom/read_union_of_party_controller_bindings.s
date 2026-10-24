; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-actor-cycle.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6B03
read_union_of_party_controller_bindings:
    lda $D9
    ora $DA
    ora $DB
    rts
