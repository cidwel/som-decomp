; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $1D81
upload_menu_title_dma_tail:
    .i16
    ldx #$0100
    stx a:$4375
    .a8
    lda #$18
    sta a:$4371
    .a8
    lda #$7E
    sta a:$4374
    .a8
    lda #$80
    sta a:$420B
    rts
