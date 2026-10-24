; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_boss_object_from_descriptor = $3438
prepare_boss_object_identity_palette_and_terrain = $2293

.segment "CODE"
.org $23DA
boss_loader_create_descriptor_object:
    lda [$30]
    inc $30
    inc $30
    jsr allocate_boss_object_from_descriptor
    jsr prepare_boss_object_identity_palette_and_terrain
    rts
