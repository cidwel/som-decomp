; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $1B65
find_regular_boss_animation_graphics_cache_slot:
    ldx a:$0FA8
find_regular_boss_animation_graphics_cache_slot_c21b68:
    lda a:$0F55,X
    bpl find_regular_boss_animation_graphics_cache_slot_c21b78
    .a8
    cmp #$FE
    beq find_regular_boss_animation_graphics_cache_slot_c21b78
    .a8
    cmp #$80
    beq find_regular_boss_animation_graphics_cache_slot_c21b78
    txa
    clc
    rts
find_regular_boss_animation_graphics_cache_slot_c21b78:
    inx
    .i8
    cpx #$4D
    bne find_regular_boss_animation_graphics_cache_slot_c21b68
    sec
    rts
