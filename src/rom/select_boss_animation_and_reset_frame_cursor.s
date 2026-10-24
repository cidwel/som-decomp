; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $1394
select_boss_animation_and_reset_frame_cursor:
    sta a:$009A,X
    .a16
    lda #$0001
    sta a:$009E,X
    stz a:$009C,X
    sep #$20
    stz a:$005A,X
    .a8
    lda #$CA
    sta a:$00A2,X
    rep #$20
    rts
