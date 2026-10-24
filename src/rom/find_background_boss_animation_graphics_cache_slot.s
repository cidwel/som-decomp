; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $1B7F
find_background_boss_animation_graphics_cache_slot:
    ldx a:$0FAA
find_background_boss_animation_graphics_cache_slot_c21b82:
    lda a:$0F55,X
    .a8
    cmp #$80
    bne find_background_boss_animation_graphics_cache_slot_c21b8c
    txa
    clc
    rts
find_background_boss_animation_graphics_cache_slot_c21b8c:
    inx
    .i8
    cpx #$4D
    bne find_background_boss_animation_graphics_cache_slot_c21b82
    sec
    rts
