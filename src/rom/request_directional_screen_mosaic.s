; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $8B3D
request_directional_screen_mosaic:
    sep #$30
    .a8
    lda #$00
    ror
    .a8
    eor #$80
    sta a:$1057
    .a8
    lda #$02
    tsb $E2
    rts
