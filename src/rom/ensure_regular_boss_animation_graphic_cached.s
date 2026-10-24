; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

derive_boss_animation_graphics_cache_key = $1B2D
enqueue_regular_boss_animation_graphics_transfer = $1B93
find_regular_boss_animation_graphics_cache_key = $1B41
find_regular_boss_animation_graphics_cache_slot = $1B65

.segment "CODE"
.org $1B03
ensure_regular_boss_animation_graphic_cached:
    jsr derive_boss_animation_graphics_cache_key
    sep #$20
    jsr find_regular_boss_animation_graphics_cache_key
    bcc ensure_regular_boss_animation_graphic_cached_c21b15
    jsr find_regular_boss_animation_graphics_cache_slot
    bcs ensure_regular_boss_animation_graphic_cached_c21b15
    jsr enqueue_regular_boss_animation_graphics_transfer
ensure_regular_boss_animation_graphic_cached_c21b15:
    rep #$20
    rts
