; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

ensure_background_boss_animation_graphic_cached = $1B18

.segment "CODE"
.org $1ACA
prepare_boss_animation_background_graphics_cache:
    lda a:$00A0,X
    sta $6E
    sep #$20
    lda a:$00A2,X
    sta $70
    lda [$6E]
    beq prepare_boss_animation_background_graphics_cache_c21afd
    sta $66
    rep #$20
    sep #$10
    inc $6E
    .i8
    ldy #$03
    .i8
    ldx #$00
prepare_boss_animation_background_graphics_cache_c21ae6:
    lda [$6E],Y
    .a16
    and #$01FF
    phx
    jsr ensure_background_boss_animation_graphic_cached
    plx
    bcs prepare_boss_animation_background_graphics_cache_c21afe
    tya
    clc
    .a16
    adc #$0004
    tay
    inx
    cpx $66
    bne prepare_boss_animation_background_graphics_cache_c21ae6
prepare_boss_animation_background_graphics_cache_c21afd:
    clc
prepare_boss_animation_background_graphics_cache_c21afe:
    rep #$30
    ldx $87
    rts
