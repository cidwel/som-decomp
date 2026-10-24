; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-palette-publication.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $F944
publish_current_palette_buffer_through_dma_channel_seven:
    sep #$10
    rep #$20
    .i8
    ldx #$00
    stx a:$2121
    .a16
    lda #$0600
    sta a:$4372
    .a16
    lda #$2200
    sta a:$4370
    .i8
    ldx #$00
    stx a:$4374
    .a16
    lda #$0200
    sta a:$4375
    .i8
    ldx #$80
    stx a:$420B
    rts
