; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_boss_object_pool_slot = $0D53

.segment "CODE"
.org $222B
boss_loader_allocate_object_operands:
    lda [$30]
    inc $30
    inc $30
    tay
    lda [$30]
    inc $30
    inc $30
    tax
    jmp allocate_boss_object_pool_slot
