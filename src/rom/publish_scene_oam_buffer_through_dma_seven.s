; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-scene-setup.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $9A91
publish_scene_oam_buffer_through_dma_seven:
    sep #$10
    rep #$20
    .a16
    lda #$0000
    sta a:$2102
    .a16
    lda #$0800
    sta a:$4372
    .a16
    lda #$0400
    sta a:$4370
    .i8
    ldx #$00
    stx a:$4374
    .a16
    lda #$0220
    sta a:$4375
    .i8
    ldx #$80
    stx a:$420B
    rts
