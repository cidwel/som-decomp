; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C8A9
convert_object_graphics_planes_inverted:
convert_object_graphics_planes_inverted_c1c8a9:
    lda a:$0001,Y
    and a:$0002,Y
    .a8
    eor #$FF
    sta f:$7E2011,X
    and a:$0000,Y
    sta f:$7E2000,X
    lda a:$0001,Y
    .a8
    eor #$FF
    sta f:$7E2001,X
    lda a:$0001,Y
    eor a:$0002,Y
    sta f:$7E2010,X
    lda a:$0004,Y
    and a:$0005,Y
    .a8
    eor #$FF
    sta f:$7E2013,X
    and a:$0003,Y
    sta f:$7E2002,X
    lda a:$0004,Y
    .a8
    eor #$FF
    sta f:$7E2003,X
    lda a:$0004,Y
    eor a:$0005,Y
    sta f:$7E2012,X
    lda a:$0007,Y
    and a:$0008,Y
    .a8
    eor #$FF
    sta f:$7E2015,X
    and a:$0006,Y
    sta f:$7E2004,X
    lda a:$0007,Y
    .a8
    eor #$FF
    sta f:$7E2005,X
    lda a:$0007,Y
    eor a:$0008,Y
    sta f:$7E2014,X
    lda a:$000A,Y
    and a:$000B,Y
    .a8
    eor #$FF
    sta f:$7E2017,X
    and a:$0009,Y
    sta f:$7E2006,X
    lda a:$000A,Y
    .a8
    eor #$FF
    sta f:$7E2007,X
    lda a:$000A,Y
    eor a:$000B,Y
    sta f:$7E2016,X
    lda a:$000D,Y
    and a:$000E,Y
    .a8
    eor #$FF
    sta f:$7E2019,X
    and a:$000C,Y
    sta f:$7E2008,X
    lda a:$000D,Y
    .a8
    eor #$FF
    sta f:$7E2009,X
    lda a:$000D,Y
    eor a:$000E,Y
    sta f:$7E2018,X
    lda a:$0010,Y
    and a:$0011,Y
    .a8
    eor #$FF
    sta f:$7E201B,X
    and a:$000F,Y
    sta f:$7E200A,X
    lda a:$0010,Y
    .a8
    eor #$FF
    sta f:$7E200B,X
    lda a:$0010,Y
    eor a:$0011,Y
    sta f:$7E201A,X
    lda a:$0013,Y
    and a:$0014,Y
    .a8
    eor #$FF
    sta f:$7E201D,X
    and a:$0012,Y
    sta f:$7E200C,X
    lda a:$0013,Y
    .a8
    eor #$FF
    sta f:$7E200D,X
    lda a:$0013,Y
    eor a:$0014,Y
    sta f:$7E201C,X
    lda a:$0016,Y
    and a:$0017,Y
    .a8
    eor #$FF
    sta f:$7E201F,X
    and a:$0015,Y
    sta f:$7E200E,X
    lda a:$0016,Y
    .a8
    eor #$FF
    sta f:$7E200F,X
    lda a:$0016,Y
    eor a:$0017,Y
    sta f:$7E201E,X
    rep #$20
    txa
    clc
    .a16
    adc #$0020
    tax
    tya
    clc
    .a16
    adc #$0018
    tay
    sep #$20
    dec $08
    beq convert_object_graphics_planes_inverted_c1c9f0
    brl convert_object_graphics_planes_inverted_c1c8a9
convert_object_graphics_planes_inverted_c1c9f0:
    rts
