; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $D8F3
restore_actor_cached_fifteen_palette_colors:
    rep #$20
    .a16
    lda #$000F
    sta $0A
    stz a:$E100,X
    ldy a:$E0F8,X
restore_actor_cached_fifteen_palette_colors_c1d900:
    lda a:$DF00,Y
    sta a:$0700,Y
    iny
    iny
    dec $0A
    bne restore_actor_cached_fifteen_palette_colors_c1d900
    rts
