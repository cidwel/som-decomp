; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-program-step-long.md.
.setcpu "65816"
.smart
.a8
.i16

execute_actor_program_step = $2552

.segment "CODE"
.org $0028
execute_actor_program_step_long:
    jsr execute_actor_program_step
    rtl
