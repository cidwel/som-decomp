; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $1B2D
derive_boss_animation_graphics_cache_key:
    sta $6C
    .a16
    and #$000F
    lsr
    sta $6A
    lda $6C
    .a16
    and #$01E0
    lsr
    lsr
    ora $6A
    sta $68
    rts
