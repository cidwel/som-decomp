; Recovered Secret of Mana USA routine; behaviour documented in docs/native-unused-return-aliases.md.
.setcpu "65816"
.smart
.a8
.i16

unused_return_internal_alias_2a = $382A

.segment "CODE"
.org $0042
unused_return_public_alias_42:
    jmp unused_return_internal_alias_2a
