; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

copy_boss_palette_with_cpu_words = $26F9

.segment "CODE"
.org $10F6
reload_boss_actor_cached_palettes:
    phy
reload_boss_actor_cached_palettes_c210f7:
    lda a:$0018,X
    beq reload_boss_actor_cached_palettes_c21115
    rep #$20
    phx
    .a16
    and #$00FF
    tax
    lda a:$033F,X
    .a16
    and #$00FF
    jsr copy_boss_palette_with_cpu_words
    plx
    sep #$20
    inx
    txa
    .a8
    and #$04
    beq reload_boss_actor_cached_palettes_c210f7
reload_boss_actor_cached_palettes_c21115:
    plx
    stz a:$0100,X
    ldx $87
    rts
