; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

set_actor_program_long = $C10020

.segment "CODE"
.org $DE11
start_uncontrolled_actor_program:
    sep #$20
    lda a:$E000,X
    beq start_uncontrolled_actor_program_c1de26
    bmi start_uncontrolled_actor_program_c1de26
    lda a:$E02C,X
    bne start_uncontrolled_actor_program_c1de26
    lda a:$E180,X
    jsl f:set_actor_program_long
start_uncontrolled_actor_program_c1de26:
    rts
