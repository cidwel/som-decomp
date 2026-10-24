; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-scene-constructor.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $FC49
configure_eight_tile_dma_channels_and_publish_row:
    rep #$30
    lda $00
    sta a:$2116
    lda a:$0000,Y
    sta a:$4302
    lda a:$0002,Y
    sta a:$4312
    lda a:$0008,Y
    sta a:$4322
    lda a:$000A,Y
    sta a:$4332
    lda a:$0010,Y
    sta a:$4342
    lda a:$0012,Y
    sta a:$4352
    lda a:$0018,Y
    sta a:$4362
    lda a:$001A,Y
    sta a:$4372
    .a16
    lda #$0020
    sta a:$4305
    sta a:$4315
    sta a:$4325
    sta a:$4335
    sta a:$4345
    sta a:$4355
    sta a:$4365
    sta a:$4375
    sep #$20
    .a8
    lda #$FF
    sta a:$420B
    rts
