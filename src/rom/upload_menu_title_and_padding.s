; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

upload_menu_title_dma_tail = $1D81

.segment "CODE"
.org $1D52
upload_menu_title_and_padding:
    lda f:$001D11
    .a8
    and #$FB
    sta f:$001D11
    .i16
    ldx #$7440
    stx a:$2116
    .a8
    lda #$01
    sta a:$4370
    .i16
    ldx #$9400
    stx a:$4372
    jsr upload_menu_title_dma_tail
    .i16
    ldx #$7540
    stx a:$2116
    .a8
    lda #$09
    sta a:$4370
    .i16
    ldx #$9500
    stx a:$4372
