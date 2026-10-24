; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $9FAA
upload_first_boss_auxiliary_tiles:
    lda f:$7EE684
    tax
    bne upload_first_boss_auxiliary_tiles_c19fb4
    brl upload_first_boss_auxiliary_tiles_c1a170
upload_first_boss_auxiliary_tiles_c19fb4:
    .a16
    lda #$6C80
    sta a:$2116
    lda a:$0D60
    sta $42
    lda a:$0D62
    sta $52
    lda a:$0D68
    sta $62
    lda a:$0D6A
    sta $72
    .a16
    lda #$207E
    sta $44
    sta $54
    sta $64
    sta $74
    .i8
    ldy #$F0
    sty a:$420B
    .a16
    lda #$6D80
    sta a:$2116
    lda a:$0D64
    sta $42
    lda a:$0D66
    sta $52
    lda a:$0D6C
    sta $62
    lda a:$0D6E
    sta $72
    .i8
    ldy #$20
    sty $45
    sty $55
    sty $65
    sty $75
    .i8
    ldy #$F0
    sty a:$420B
    dex
    bne upload_first_boss_auxiliary_tiles_c1a00d
upload_first_boss_auxiliary_tiles_c1a00a:
    brl upload_first_boss_auxiliary_tiles_c1a170
upload_first_boss_auxiliary_tiles_c1a00d:
    dex
    beq upload_first_boss_auxiliary_tiles_c1a00a
    .a16
    lda #$6CC0
    sta a:$2116
    lda a:$0D70
    sta $42
    lda a:$0D72
    sta $52
    lda a:$0D78
    sta $62
    lda a:$0D7A
    sta $72
    .i8
    ldy #$20
    sty $45
    sty $55
    sty $65
    sty $75
    .i8
    ldy #$F0
    sty a:$420B
    .a16
    lda #$6DC0
    sta a:$2116
    lda a:$0D74
    sta $42
    lda a:$0D76
    sta $52
    lda a:$0D7C
    sta $62
    lda a:$0D7E
    sta $72
    .i8
    ldy #$20
    sty $45
    sty $55
    sty $65
    sty $75
    .i8
    ldy #$F0
    sty a:$420B
    dex
    bne upload_first_boss_auxiliary_tiles_c1a068
upload_first_boss_auxiliary_tiles_c1a065:
    brl upload_first_boss_auxiliary_tiles_c1a170
upload_first_boss_auxiliary_tiles_c1a068:
    dex
    beq upload_first_boss_auxiliary_tiles_c1a065
    .a16
    lda #$6E00
    sta a:$2116
    lda a:$0D80
    sta $42
    lda a:$0D82
    sta $52
    lda a:$0D88
    sta $62
    lda a:$0D8A
    sta $72
    .i8
    ldy #$20
    sty $45
    sty $55
    sty $65
    sty $75
    .i8
    ldy #$F0
    sty a:$420B
    .a16
    lda #$6F00
    sta a:$2116
    lda a:$0D84
    sta $42
    lda a:$0D86
    sta $52
    lda a:$0D8C
    sta $62
    lda a:$0D8E
    sta $72
    .i8
    ldy #$20
    sty $45
    sty $55
    sty $65
    sty $75
    .i8
    ldy #$F0
    sty a:$420B
    dex
    bne upload_first_boss_auxiliary_tiles_c1a0c3
upload_first_boss_auxiliary_tiles_c1a0c0:
    brl upload_first_boss_auxiliary_tiles_c1a170
upload_first_boss_auxiliary_tiles_c1a0c3:
    dex
    beq upload_first_boss_auxiliary_tiles_c1a0c0
    .a16
    lda #$6E40
    sta a:$2116
    lda a:$0D90
    sta $42
    lda a:$0D92
    sta $52
    lda a:$0D98
    sta $62
    lda a:$0D9A
    sta $72
    .i8
    ldy #$20
    sty $45
    sty $55
    sty $65
    sty $75
    .i8
    ldy #$F0
    sty a:$420B
    .a16
    lda #$6F40
    sta a:$2116
    lda a:$0D94
    sta $42
    lda a:$0D96
    sta $52
    lda a:$0D9C
    sta $62
    lda a:$0D9E
    sta $72
    .i8
    ldy #$20
    sty $45
    sty $55
    sty $65
    sty $75
    .i8
    ldy #$F0
    sty a:$420B
    dex
    beq upload_first_boss_auxiliary_tiles_c1a170
    dex
    beq upload_first_boss_auxiliary_tiles_c1a170
upload_first_boss_auxiliary_tiles_c1a11e:
    .a16
    lda #$6E80
    sta a:$2116
    lda a:$0DA0
    sta $42
    lda a:$0DA2
    sta $52
    lda a:$0DA8
    sta $62
    lda a:$0DAA
    sta $72
    .i8
    ldy #$20
    sty $45
    sty $55
    sty $65
    sty $75
    .i8
    ldy #$F0
    sty a:$420B
    .a16
    lda #$6F80
    sta a:$2116
    lda a:$0DA4
    sta $42
    lda a:$0DA6
    sta $52
    lda a:$0DAC
    sta $62
    lda a:$0DAE
    sta $72
    .i8
    ldy #$20
    sty $45
    sty $55
    sty $65
    sty $75
    .i8
    ldy #$F0
    sty a:$420B
upload_first_boss_auxiliary_tiles_c1a170:
    lda f:$7EE68D
    tax
    beq upload_first_boss_auxiliary_tiles_c1a183
    .a16
    and #$FF00
    sta f:$7EE68D
    .i8
    ldx #$04
    brl upload_first_boss_auxiliary_tiles_c1a11e
upload_first_boss_auxiliary_tiles_c1a183:
    pld
    rtl
