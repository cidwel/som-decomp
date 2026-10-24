; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-vram-initialization.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $F9E1
configure_and_trigger_dma_seven_from_word_arguments:
    sta a:$4370
    stx a:$4372
    sty a:$4375
    sep #$20
    .a8
    lda #$80
    sta a:$420B
    rts
