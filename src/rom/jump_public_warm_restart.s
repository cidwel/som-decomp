; Recovered Secret of Mana USA routine; behaviour documented in docs/event-party-warm-aliases.md.
.setcpu "65816"
.smart
.a8
.i16

jump_long_warm_restart = $009B

.segment "CODE"
.org $0075
jump_public_warm_restart:
    jmp jump_long_warm_restart
