; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C731
convert_object_graphics_planes_xor:
convert_object_graphics_planes_xor_c1c731:
    lda a:$0000,Y
    .a8
    eor #$FF
    sta f:$7E2000,X
    .a8
    eor #$FF
    eor a:$0001,Y
    sta f:$7E2001,X
    lda a:$0002,Y
    .a8
    eor #$FF
    and f:$7E2001,X
    sta f:$7E2010,X
    lda a:$0000,Y
    and a:$0001,Y
    eor a:$0002,Y
    sta f:$7E2011,X
    lda a:$0003,Y
    .a8
    eor #$FF
    sta f:$7E2002,X
    .a8
    eor #$FF
    eor a:$0004,Y
    sta f:$7E2003,X
    lda a:$0005,Y
    .a8
    eor #$FF
    and f:$7E2003,X
    sta f:$7E2012,X
    lda a:$0003,Y
    and a:$0004,Y
    eor a:$0005,Y
    sta f:$7E2013,X
    lda a:$0006,Y
    .a8
    eor #$FF
    sta f:$7E2004,X
    .a8
    eor #$FF
    eor a:$0007,Y
    sta f:$7E2005,X
    lda a:$0008,Y
    .a8
    eor #$FF
    and f:$7E2005,X
    sta f:$7E2014,X
    lda a:$0006,Y
    and a:$0007,Y
    eor a:$0008,Y
    sta f:$7E2015,X
    lda a:$0009,Y
    .a8
    eor #$FF
    sta f:$7E2006,X
    .a8
    eor #$FF
    eor a:$000A,Y
    sta f:$7E2007,X
    lda a:$000B,Y
    .a8
    eor #$FF
    and f:$7E2007,X
    sta f:$7E2016,X
    lda a:$0009,Y
    and a:$000A,Y
    eor a:$000B,Y
    sta f:$7E2017,X
    lda a:$000C,Y
    .a8
    eor #$FF
    sta f:$7E2008,X
    .a8
    eor #$FF
    eor a:$000D,Y
    sta f:$7E2009,X
    lda a:$000E,Y
    .a8
    eor #$FF
    and f:$7E2009,X
    sta f:$7E2018,X
    lda a:$000C,Y
    and a:$000D,Y
    eor a:$000E,Y
    sta f:$7E2019,X
    lda a:$000F,Y
    .a8
    eor #$FF
    sta f:$7E200A,X
    .a8
    eor #$FF
    eor a:$0010,Y
    sta f:$7E200B,X
    lda a:$0011,Y
    .a8
    eor #$FF
    and f:$7E200B,X
    sta f:$7E201A,X
    lda a:$000F,Y
    and a:$0010,Y
    eor a:$0011,Y
    sta f:$7E201B,X
    lda a:$0012,Y
    .a8
    eor #$FF
    sta f:$7E200C,X
    .a8
    eor #$FF
    eor a:$0013,Y
    sta f:$7E200D,X
    lda a:$0014,Y
    .a8
    eor #$FF
    and f:$7E200D,X
    sta f:$7E201C,X
    lda a:$0012,Y
    and a:$0013,Y
    eor a:$0014,Y
    sta f:$7E201D,X
    lda a:$0015,Y
    .a8
    eor #$FF
    sta f:$7E200E,X
    .a8
    eor #$FF
    eor a:$0016,Y
    sta f:$7E200F,X
    lda a:$0017,Y
    .a8
    eor #$FF
    and f:$7E200F,X
    sta f:$7E201E,X
    lda a:$0015,Y
    and a:$0016,Y
    eor a:$0017,Y
    sta f:$7E201F,X
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
    beq convert_object_graphics_planes_xor_c1c8a8
    brl convert_object_graphics_planes_xor_c1c731
convert_object_graphics_planes_xor_c1c8a8:
    rts
