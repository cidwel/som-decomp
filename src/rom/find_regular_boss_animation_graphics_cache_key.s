; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $1B41
find_regular_boss_animation_graphics_cache_key:
    .i8
    ldx #$00
    lda $68
find_regular_boss_animation_graphics_cache_key_c21b45:
    cmp a:$0F55,X
    beq find_regular_boss_animation_graphics_cache_key_c21b51
    inx
    cpx a:$0FA8
    bcc find_regular_boss_animation_graphics_cache_key_c21b45
    rts
find_regular_boss_animation_graphics_cache_key_c21b51:
    clc
    rts
