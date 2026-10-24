; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-restore.md.
.setcpu "65816"
.smart
.a8
.i16

finish_previous_cast_native_long_jump = $385E

.segment "CODE"
.org $3806
finish_previous_cast_internal_jump:
    jmp finish_previous_cast_native_long_jump
