; Recovered Secret of Mana USA routine; behaviour documented in docs/native-unused-return-aliases.md.
.setcpu "65816"
.smart
.a8
.i16

unused_cast_completion_return = $385D

.segment "CODE"
.org $3839
unused_return_internal_alias_39:
    jmp unused_cast_completion_return
