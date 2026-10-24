; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $1B53
find_background_boss_animation_graphics_cache_key:
    .i8
    ldx #$30
    lda $68
find_background_boss_animation_graphics_cache_key_c21b57:
    cmp a:$0F55,X
    beq find_background_boss_animation_graphics_cache_key_c21b63
    inx
    cpx a:$0FAA
    bcc find_background_boss_animation_graphics_cache_key_c21b57
    rts
find_background_boss_animation_graphics_cache_key_c21b63:
    clc
    rts
