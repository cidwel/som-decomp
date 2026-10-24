; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $97F0
upload_first_hero_auxiliary_tiles:
    lda f:$7EE084
    tax
    bne upload_first_hero_auxiliary_tiles_c197fa
    brl upload_first_hero_auxiliary_tiles_c199b6
upload_first_hero_auxiliary_tiles_c197fa:
    .a16
    lda #$7440
    sta a:$2116
    lda a:$0C60
    sta $42
    lda a:$0C62
    sta $52
    lda a:$0C68
    sta $62
    lda a:$0C6A
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
    lda #$7540
    sta a:$2116
    lda a:$0C64
    sta $42
    lda a:$0C66
    sta $52
    lda a:$0C6C
    sta $62
    lda a:$0C6E
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
    bne upload_first_hero_auxiliary_tiles_c19853
upload_first_hero_auxiliary_tiles_c19850:
    brl upload_first_hero_auxiliary_tiles_c199b6
upload_first_hero_auxiliary_tiles_c19853:
    dex
    beq upload_first_hero_auxiliary_tiles_c19850
    .a16
    lda #$7480
    sta a:$2116
    lda a:$0C70
    sta $42
    lda a:$0C72
    sta $52
    lda a:$0C78
    sta $62
    lda a:$0C7A
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
    lda #$7580
    sta a:$2116
    lda a:$0C74
    sta $42
    lda a:$0C76
    sta $52
    lda a:$0C7C
    sta $62
    lda a:$0C7E
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
    bne upload_first_hero_auxiliary_tiles_c198ae
upload_first_hero_auxiliary_tiles_c198ab:
    brl upload_first_hero_auxiliary_tiles_c199b6
upload_first_hero_auxiliary_tiles_c198ae:
    dex
    beq upload_first_hero_auxiliary_tiles_c198ab
    .a16
    lda #$74C0
    sta a:$2116
    lda a:$0C80
    sta $42
    lda a:$0C82
    sta $52
    lda a:$0C88
    sta $62
    lda a:$0C8A
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
    lda #$75C0
    sta a:$2116
    lda a:$0C84
    sta $42
    lda a:$0C86
    sta $52
    lda a:$0C8C
    sta $62
    lda a:$0C8E
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
    bne upload_first_hero_auxiliary_tiles_c19909
upload_first_hero_auxiliary_tiles_c19906:
    brl upload_first_hero_auxiliary_tiles_c199b6
upload_first_hero_auxiliary_tiles_c19909:
    dex
    beq upload_first_hero_auxiliary_tiles_c19906
    .a16
    lda #$7600
    sta a:$2116
    lda a:$0C90
    sta $42
    lda a:$0C92
    sta $52
    lda a:$0C98
    sta $62
    lda a:$0C9A
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
    lda #$7700
    sta a:$2116
    lda a:$0C94
    sta $42
    lda a:$0C96
    sta $52
    lda a:$0C9C
    sta $62
    lda a:$0C9E
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
    beq upload_first_hero_auxiliary_tiles_c199b6
    dex
    beq upload_first_hero_auxiliary_tiles_c199b6
upload_first_hero_auxiliary_tiles_c19964:
    .a16
    lda #$7640
    sta a:$2116
    lda a:$0CA0
    sta $42
    lda a:$0CA2
    sta $52
    lda a:$0CA8
    sta $62
    lda a:$0CAA
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
    lda #$7740
    sta a:$2116
    lda a:$0CA4
    sta $42
    lda a:$0CA6
    sta $52
    lda a:$0CAC
    sta $62
    lda a:$0CAE
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
upload_first_hero_auxiliary_tiles_c199b6:
    lda f:$7EE08D
    tax
    beq upload_first_hero_auxiliary_tiles_c199c9
    .a16
    and #$FF00
    sta f:$7EE08D
    .i8
    ldx #$04
    brl upload_first_hero_auxiliary_tiles_c19964
upload_first_hero_auxiliary_tiles_c199c9:
    pld
    rtl
