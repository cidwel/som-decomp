; Recovered Secret of Mana USA routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16

set_actor_program_and_status_continuation = $25B6



.segment "CODE"
.org $0020
set_actor_program_long:
    jsr set_actor_program_and_status_continuation
    rtl
