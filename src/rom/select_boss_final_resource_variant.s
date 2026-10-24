; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_boss_resource_vram_high_expansion = $25AD

.segment "CODE"
.org $8F20
select_boss_final_resource_variant:
    lda a:$E6B6
    bne select_boss_final_resource_variant_c28f2c
    .a16
    lda #$0019
    jsr prepare_boss_resource_vram_high_expansion
    rts
select_boss_final_resource_variant_c28f2c:
    .a16
    lda #$0018
    jsr prepare_boss_resource_vram_high_expansion
    rts
