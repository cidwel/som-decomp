; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C486
advance_map_graphics_two_tile_frame_pointer:
    rep #$20
    lda $06
    clc
    .a16
    adc #$0040
    sta $06
    rts
