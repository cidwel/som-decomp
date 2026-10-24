; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-restore.md.
.setcpu "65816"
.smart
.a8
.i16

finish_previous_cast_internal_jump = $3806

.segment "CODE"
.org $001E
finish_previous_cast_public_jump:
    jmp finish_previous_cast_internal_jump
