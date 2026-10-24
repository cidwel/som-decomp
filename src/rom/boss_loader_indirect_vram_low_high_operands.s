; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

decompress_boss_resource_to_vram_low_high = $2614

.segment "CODE"
.org $2464
boss_loader_indirect_vram_low_high_operands:
    lda [$30]
    inc $30
    inc $30
    jmp decompress_boss_resource_to_vram_low_high
