; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_boss_object_pool_slot = $0D53
prepare_boss_object_identity_palette_and_terrain = $2293

.segment "CODE"
.org $227E
boss_loader_allocate_and_prepare_object:
    lda [$30]
    inc $30
    inc $30
    tay
    lda [$30]
    inc $30
    inc $30
    tax
    jsr allocate_boss_object_pool_slot
    jsr prepare_boss_object_identity_palette_and_terrain
    rts
