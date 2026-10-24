; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native7f-frame-requests.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $95A0
publish_native7f_single_mode7_frame_dma_request:
    .a16
    lda #$0001
    sta a:$0352
    lda a:$0096,X
    dec
    xba
    asl
    asl
    asl
    sta $95
    clc
    .a16
    adc #$4000
    sta a:$0353
    lda $95
    sta a:$0355
    rts
