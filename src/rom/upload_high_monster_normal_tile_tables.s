; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $ADFD
upload_high_monster_normal_tile_tables:
    lda f:$7EF283
    tax
    bne upload_high_monster_normal_tile_tables_c1ae07
    brl upload_high_monster_normal_tile_tables_c1aeb9
upload_high_monster_normal_tile_tables_c1ae07:
    .a16
    lda #$6A00
    sta a:$2116
    lda a:$0F20
    sta $42
    lda a:$0F22
    sta $52
    lda a:$0F28
    sta $62
    lda a:$0F2A
    sta $72
    lda f:$7EF282
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
    lda #$6B00
    sta a:$2116
    lda a:$0F24
    sta $42
    lda a:$0F26
    sta $52
    lda a:$0F2C
    sta $62
    lda a:$0F2E
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
    beq upload_high_monster_normal_tile_tables_c1aeb9
    dex
    beq upload_high_monster_normal_tile_tables_c1aeb9
    .a16
    lda #$6A40
    sta a:$2116
    lda a:$0F30
    sta $42
    lda a:$0F32
    sta $52
    lda a:$0F38
    sta $62
    lda a:$0F3A
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
    lda #$6B40
    sta a:$2116
    lda a:$0F34
    sta $42
    lda a:$0F36
    sta $52
    lda a:$0F3C
    sta $62
    lda a:$0F3E
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
upload_high_monster_normal_tile_tables_c1aeb9:
    lda f:$7EF483
    tax
    bne upload_high_monster_normal_tile_tables_c1aec3
    brl upload_high_monster_normal_tile_tables_c1af75
upload_high_monster_normal_tile_tables_c1aec3:
    .a16
    lda #$6A80
    sta a:$2116
    lda a:$0F40
    sta $42
    lda a:$0F42
    sta $52
    lda a:$0F48
    sta $62
    lda a:$0F4A
    sta $72
    lda f:$7EF482
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
    lda #$6B80
    sta a:$2116
    lda a:$0F44
    sta $42
    lda a:$0F46
    sta $52
    lda a:$0F4C
    sta $62
    lda a:$0F4E
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
    beq upload_high_monster_normal_tile_tables_c1af75
    dex
    beq upload_high_monster_normal_tile_tables_c1af75
    .a16
    lda #$6AC0
    sta a:$2116
    lda a:$0F50
    sta $42
    lda a:$0F52
    sta $52
    lda a:$0F58
    sta $62
    lda a:$0F5A
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
    lda #$6BC0
    sta a:$2116
    lda a:$0F54
    sta $42
    lda a:$0F56
    sta $52
    lda a:$0F5C
    sta $62
    lda a:$0F5E
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
upload_high_monster_normal_tile_tables_c1af75:
    lda f:$7EF683
    tax
    bne upload_high_monster_normal_tile_tables_c1af7f
    brl upload_high_monster_normal_tile_tables_c1b031
upload_high_monster_normal_tile_tables_c1af7f:
    .a16
    lda #$6C00
    sta a:$2116
    lda a:$0F60
    sta $42
    lda a:$0F62
    sta $52
    lda a:$0F68
    sta $62
    lda a:$0F6A
    sta $72
    lda f:$7EF682
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
    lda #$6D00
    sta a:$2116
    lda a:$0F64
    sta $42
    lda a:$0F66
    sta $52
    lda a:$0F6C
    sta $62
    lda a:$0F6E
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
    beq upload_high_monster_normal_tile_tables_c1b031
    dex
    beq upload_high_monster_normal_tile_tables_c1b031
    .a16
    lda #$6C40
    sta a:$2116
    lda a:$0F70
    sta $42
    lda a:$0F72
    sta $52
    lda a:$0F78
    sta $62
    lda a:$0F7A
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
    lda #$6D40
    sta a:$2116
    lda a:$0F74
    sta $42
    lda a:$0F76
    sta $52
    lda a:$0F7C
    sta $62
    lda a:$0F7E
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
upload_high_monster_normal_tile_tables_c1b031:
    pld
    rtl
