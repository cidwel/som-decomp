; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

reset_boss_object_pool_through_dma = $0CEA

.segment "CODE"
.org $223D
boss_loader_reset_object_pool:
    jmp reset_boss_object_pool_through_dma
