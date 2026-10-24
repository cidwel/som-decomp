; Recovered Secret of Mana USA routine; behaviour documented in docs/event-party-warm-aliases.md.
.setcpu "65816"
.smart
.a8
.i16

jump_to_warm_boot = $C10018

.segment "CODE"
.org $009B
jump_long_warm_restart:
    jml f:jump_to_warm_boot
