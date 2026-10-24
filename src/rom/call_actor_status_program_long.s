; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

call_actor_status_program = $2698

.segment "CODE"
.org $0024
call_actor_status_program_long:
    jsr call_actor_status_program
    rtl
