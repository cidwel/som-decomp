; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

upload_first_hero_auxiliary_tiles = $97F0

.segment "CODE"
.org $95BC
upload_three_hero_normal_tile_tables:
    lda f:$7EE083
    tax
    bne upload_three_hero_normal_tile_tables_c195c6
    brl upload_three_hero_normal_tile_tables_c19678
upload_three_hero_normal_tile_tables_c195c6:
    .a16
    lda #$7C00
    sta a:$2116
    lda a:$0C00
    sta $42
    lda a:$0C02
    sta $52
    lda a:$0C08
    sta $62
    lda a:$0C0A
    sta $72
    lda f:$7EE082
    .a16
    and #$00FF
    .a16
    ora #$2000
    sta $44
    sta $54
    sta $64
    sta $74
    .i8
    ldy #$F0
    sty a:$420B
    .a16
    lda #$7D00
    sta a:$2116
    lda a:$0C04
    sta $42
    lda a:$0C06
    sta $52
    lda a:$0C0C
    sta $62
    lda a:$0C0E
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
    beq upload_three_hero_normal_tile_tables_c19678
    dex
    beq upload_three_hero_normal_tile_tables_c19678
    .a16
    lda #$7C40
    sta a:$2116
    lda a:$0C10
    sta $42
    lda a:$0C12
    sta $52
    lda a:$0C18
    sta $62
    lda a:$0C1A
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
    lda #$7D40
    sta a:$2116
    lda a:$0C14
    sta $42
    lda a:$0C16
    sta $52
    lda a:$0C1C
    sta $62
    lda a:$0C1E
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
upload_three_hero_normal_tile_tables_c19678:
    lda f:$7EE283
    tax
    bne upload_three_hero_normal_tile_tables_c19682
    brl upload_three_hero_normal_tile_tables_c19734
upload_three_hero_normal_tile_tables_c19682:
    .a16
    lda #$7C80
    sta a:$2116
    lda a:$0C20
    sta $42
    lda a:$0C22
    sta $52
    lda a:$0C28
    sta $62
    lda a:$0C2A
    sta $72
    lda f:$7EE282
    .a16
    and #$00FF
    .a16
    ora #$2000
    sta $44
    sta $54
    sta $64
    sta $74
    .i8
    ldy #$F0
    sty a:$420B
    .a16
    lda #$7D80
    sta a:$2116
    lda a:$0C24
    sta $42
    lda a:$0C26
    sta $52
    lda a:$0C2C
    sta $62
    lda a:$0C2E
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
    beq upload_three_hero_normal_tile_tables_c19734
    dex
    beq upload_three_hero_normal_tile_tables_c19734
    .a16
    lda #$7CC0
    sta a:$2116
    lda a:$0C30
    sta $42
    lda a:$0C32
    sta $52
    lda a:$0C38
    sta $62
    lda a:$0C3A
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
    lda #$7DC0
    sta a:$2116
    lda a:$0C34
    sta $42
    lda a:$0C36
    sta $52
    lda a:$0C3C
    sta $62
    lda a:$0C3E
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
upload_three_hero_normal_tile_tables_c19734:
    lda f:$7EE483
    tax
    bne upload_three_hero_normal_tile_tables_c1973e
    brl upload_first_hero_auxiliary_tiles
upload_three_hero_normal_tile_tables_c1973e:
    .a16
    lda #$7E00
    sta a:$2116
    lda a:$0C40
    sta $42
    lda a:$0C42
    sta $52
    lda a:$0C48
    sta $62
    lda a:$0C4A
    sta $72
    lda f:$7EE482
    .a16
    and #$00FF
    .a16
    ora #$2000
    sta $44
    sta $54
    sta $64
    sta $74
    .i8
    ldy #$F0
    sty a:$420B
    .a16
    lda #$7F00
    sta a:$2116
    lda a:$0C44
    sta $42
    lda a:$0C46
    sta $52
    lda a:$0C4C
    sta $62
    lda a:$0C4E
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
    beq upload_first_hero_auxiliary_tiles
    dex
    beq upload_first_hero_auxiliary_tiles
    .a16
    lda #$7E40
    sta a:$2116
    lda a:$0C50
    sta $42
    lda a:$0C52
    sta $52
    lda a:$0C58
    sta $62
    lda a:$0C5A
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
    lda #$7F40
    sta a:$2116
    lda a:$0C54
    sta $42
    lda a:$0C56
    sta $52
    lda a:$0C5C
    sta $62
    lda a:$0C5E
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
