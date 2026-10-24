; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_boss_loader_resource_expansion = $24C3

.segment "CODE"
.org $2249
boss_loader_ram_resource_operands:
    lda [$30]
    inc $30
    inc $30
    jmp prepare_boss_loader_resource_expansion
