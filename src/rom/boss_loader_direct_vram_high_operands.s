; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_boss_resource_vram_high_expansion = $25AD

.segment "CODE"
.org $23E7
boss_loader_direct_vram_high_operands:
    lda [$30]
    inc $30
    inc $30
    jmp prepare_boss_resource_vram_high_expansion
