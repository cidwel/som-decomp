; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $852B
clear_sixteen_floating_number_tile_words:
    rep #$20
    ldy a:$E06C,X
    .a16
    lda #$CB00
    sta a:$0000,Y
    sta a:$0002,Y
    sta a:$0004,Y
    sta a:$0006,Y
    sta a:$0008,Y
    sta a:$000A,Y
    sta a:$000C,Y
    sta a:$000E,Y
    sta a:$0010,Y
    sta a:$0012,Y
    sta a:$0014,Y
    sta a:$0016,Y
    sta a:$0018,Y
    sta a:$001A,Y
    sta a:$001C,Y
    sta a:$001E,Y
    rts
