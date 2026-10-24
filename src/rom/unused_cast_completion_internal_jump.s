; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-restore.md.
.setcpu "65816"
.smart
.a8
.i16

unused_cast_completion_return = $385D

.segment "CODE"
.org $381B
unused_cast_completion_internal_jump:
    jmp unused_cast_completion_return
