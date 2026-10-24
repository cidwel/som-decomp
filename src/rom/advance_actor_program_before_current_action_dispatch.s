; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-program-step-caller.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c10028 = $C10028

.segment "CODE"
.org $D942
advance_actor_program_before_current_action_dispatch:
    sep #$20
    phx
    stz a:$E064,X
    jsl f:routine_c10028
    plx
