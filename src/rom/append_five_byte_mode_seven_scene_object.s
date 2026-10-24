; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-mode7-transition.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $4604
append_five_byte_mode_seven_scene_object:
    rep #$20
    lda $4E
    asl
    asl
    clc
    adc $4E
    clc
    .a16
    adc #$1100
    tax
    inc $4E
    sep #$20
    lda $21
    sta $00,X
    lda $20
    sta $01,X
    lda $22
    sta $02,X
    lda $24
    sta $03,X
    lda $25
    sta $04,X
    rtl
