; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $11EC
request_boss_actor_cached_palette_reload:
    ldx $87
    .a8
    lda #$80
    sta a:$0100,X
    rts
