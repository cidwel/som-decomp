; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

boss_loader_reserved_parameter_return = $272C

.segment "CODE"
.org $226C
boss_loader_reserved_parameter_14:
    lda [$30]
    inc $30
    inc $30
    jmp boss_loader_reserved_parameter_return
