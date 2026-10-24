; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

derive_boss_animation_graphics_cache_key = $1B2D
enqueue_background_boss_animation_graphics_transfer = $1BE5
find_background_boss_animation_graphics_cache_key = $1B53
find_background_boss_animation_graphics_cache_slot = $1B7F

.segment "CODE"
.org $1B18
ensure_background_boss_animation_graphic_cached:
    jsr derive_boss_animation_graphics_cache_key
    sep #$20
    jsr find_background_boss_animation_graphics_cache_key
    bcc ensure_background_boss_animation_graphic_cached_c21b2a
    jsr find_background_boss_animation_graphics_cache_slot
    bcs ensure_background_boss_animation_graphic_cached_c21b2a
    jsr enqueue_background_boss_animation_graphics_transfer
ensure_background_boss_animation_graphic_cached_c21b2a:
    rep #$20
    rts
