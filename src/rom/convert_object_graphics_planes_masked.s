; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C5D1
convert_object_graphics_planes_masked:
convert_object_graphics_planes_masked_c1c5d1:
    lda a:$0001,Y
    and a:$0002,Y
    .a8
    eor #$FF
    sta $00
    and a:$0000,Y
    sta f:$7E2000,X
    lda a:$0001,Y
    and $00
    sta f:$7E2001,X
    lda a:$0002,Y
    and $00
    sta f:$7E2010,X
    .a8
    lda #$00
    sta f:$7E2011,X
    lda a:$0004,Y
    and a:$0005,Y
    .a8
    eor #$FF
    sta $00
    and a:$0003,Y
    sta f:$7E2002,X
    lda a:$0004,Y
    and $00
    sta f:$7E2003,X
    lda a:$0005,Y
    and $00
    sta f:$7E2012,X
    .a8
    lda #$00
    sta f:$7E2013,X
    lda a:$0007,Y
    and a:$0008,Y
    .a8
    eor #$FF
    sta $00
    and a:$0006,Y
    sta f:$7E2004,X
    lda a:$0007,Y
    and $00
    sta f:$7E2005,X
    lda a:$0008,Y
    and $00
    sta f:$7E2014,X
    .a8
    lda #$00
    sta f:$7E2015,X
    lda a:$000A,Y
    and a:$000B,Y
    .a8
    eor #$FF
    sta $00
    and a:$0009,Y
    sta f:$7E2006,X
    lda a:$000A,Y
    and $00
    sta f:$7E2007,X
    lda a:$000B,Y
    and $00
    sta f:$7E2016,X
    .a8
    lda #$00
    sta f:$7E2017,X
    lda a:$000D,Y
    and a:$000E,Y
    .a8
    eor #$FF
    sta $00
    and a:$000C,Y
    sta f:$7E2008,X
    lda a:$000D,Y
    and $00
    sta f:$7E2009,X
    lda a:$000E,Y
    and $00
    sta f:$7E2018,X
    .a8
    lda #$00
    sta f:$7E2019,X
    lda a:$0010,Y
    and a:$0011,Y
    .a8
    eor #$FF
    sta $00
    and a:$000F,Y
    sta f:$7E200A,X
    lda a:$0010,Y
    and $00
    sta f:$7E200B,X
    lda a:$0011,Y
    and $00
    sta f:$7E201A,X
    .a8
    lda #$00
    sta f:$7E201B,X
    lda a:$0013,Y
    and a:$0014,Y
    .a8
    eor #$FF
    sta $00
    and a:$0012,Y
    sta f:$7E200C,X
    lda a:$0013,Y
    and $00
    sta f:$7E200D,X
    lda a:$0014,Y
    and $00
    sta f:$7E201C,X
    .a8
    lda #$00
    sta f:$7E201D,X
    lda a:$0016,Y
    and a:$0017,Y
    .a8
    eor #$FF
    sta $00
    and a:$0015,Y
    sta f:$7E200E,X
    lda a:$0016,Y
    and $00
    sta f:$7E200F,X
    lda a:$0017,Y
    and $00
    sta f:$7E201E,X
    .a8
    lda #$00
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
    beq convert_object_graphics_planes_masked_c1c730
    brl convert_object_graphics_planes_masked_c1c5d1
convert_object_graphics_planes_masked_c1c730:
    rts
