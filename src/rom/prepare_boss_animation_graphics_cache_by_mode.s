; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_boss_animation_background_graphics_cache = $1ACA
prepare_boss_animation_regular_graphics_cache = $1A91

.segment "CODE"
.org $1A81
prepare_boss_animation_graphics_cache_by_mode:
    lda a:$0098,X
    .a16
    bit #$1000
    beq prepare_boss_animation_graphics_cache_by_mode_c21a8d
    jsr prepare_boss_animation_regular_graphics_cache
    rts
prepare_boss_animation_graphics_cache_by_mode_c21a8d:
    jsr prepare_boss_animation_background_graphics_cache
    rts
