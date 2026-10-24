; Recovered Secret of Mana USA routine; behaviour documented in docs/native-unused-return-aliases.md.
.setcpu "65816"
.smart
.a8
.i16

unused_return_internal_alias_51 = $3851

.segment "CODE"
.org $0069
unused_return_public_alias_69:
    jmp unused_return_internal_alias_51
