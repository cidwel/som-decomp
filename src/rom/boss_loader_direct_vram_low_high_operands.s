; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_boss_resource_vram_word_expansion = $2534

.segment "CODE"
.org $2252
boss_loader_direct_vram_low_high_operands:
    lda [$30]
    inc $30
    inc $30
    jmp prepare_boss_resource_vram_word_expansion
