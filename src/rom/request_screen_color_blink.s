; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $8B4C
request_screen_color_blink:
    sep #$30
    .a8
    lda #$40
    sta a:$1057
    lda $E6
    sta a:$1058
    .a8
    lda #$04
    tsb $E2
    rts
