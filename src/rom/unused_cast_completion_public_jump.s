; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-restore.md.
.setcpu "65816"
.smart
.a8
.i16

unused_cast_completion_internal_jump = $381B

.segment "CODE"
.org $0033
unused_cast_completion_public_jump:
    jmp unused_cast_completion_internal_jump
