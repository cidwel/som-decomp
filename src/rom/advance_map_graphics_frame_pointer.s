; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $B406
advance_map_graphics_frame_pointer:
    rep #$20
    lda $06
    clc
    .a16
    adc #$0020
    sta $06
    rts
