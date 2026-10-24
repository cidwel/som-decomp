; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

load_boss_palette_through_wram_dma = $26AC

.segment "CODE"
.org $2218
boss_loader_load_palette_operands:
    lda [$30]
    inc $30
    inc $30
    tay
    lda [$30]
    inc $30
    inc $30
    tax
    tya
    jmp load_boss_palette_through_wram_dma
