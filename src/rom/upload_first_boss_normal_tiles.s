; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

upload_first_boss_auxiliary_tiles = $9FAA

.segment "CODE"
.org $9D7F
upload_first_boss_normal_tiles:
    lda f:$7EE683
    tax
    bne upload_first_boss_normal_tiles_c19d89
    brl upload_first_boss_auxiliary_tiles
upload_first_boss_normal_tiles_c19d89:
    .a16
    lda #$6400
    sta a:$2116
    lda a:$0E60
    sta $42
    lda a:$0E62
    sta $52
    lda a:$0E68
    sta $62
    lda a:$0E6A
    sta $72
    lda f:$7EE682
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
    lda #$6500
    sta a:$2116
    lda a:$0E64
    sta $42
    lda a:$0E66
    sta $52
    lda a:$0E6C
    sta $62
    lda a:$0E6E
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
    bne upload_first_boss_normal_tiles_c19de9
upload_first_boss_normal_tiles_c19de6:
    brl upload_first_boss_auxiliary_tiles
upload_first_boss_normal_tiles_c19de9:
    dex
    beq upload_first_boss_normal_tiles_c19de6
    .a16
    lda #$6440
    sta a:$2116
    lda a:$0E70
    sta $42
    lda a:$0E72
    sta $52
    lda a:$0E78
    sta $62
    lda a:$0E7A
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
    lda #$6540
    sta a:$2116
    lda a:$0E74
    sta $42
    lda a:$0E76
    sta $52
    lda a:$0E7C
    sta $62
    lda a:$0E7E
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
    bne upload_first_boss_normal_tiles_c19e44
upload_first_boss_normal_tiles_c19e41:
    brl upload_first_boss_auxiliary_tiles
upload_first_boss_normal_tiles_c19e44:
    dex
    beq upload_first_boss_normal_tiles_c19e41
    .a16
    lda #$6480
    sta a:$2116
    lda a:$0E80
    sta $42
    lda a:$0E82
    sta $52
    lda a:$0E88
    sta $62
    lda a:$0E8A
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
    lda #$6580
    sta a:$2116
    lda a:$0E84
    sta $42
    lda a:$0E86
    sta $52
    lda a:$0E8C
    sta $62
    lda a:$0E8E
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
    bne upload_first_boss_normal_tiles_c19e9f
upload_first_boss_normal_tiles_c19e9c:
    brl upload_first_boss_auxiliary_tiles
upload_first_boss_normal_tiles_c19e9f:
    dex
    beq upload_first_boss_normal_tiles_c19e9c
    .a16
    lda #$64C0
    sta a:$2116
    lda a:$0E90
    sta $42
    lda a:$0E92
    sta $52
    lda a:$0E98
    sta $62
    lda a:$0E9A
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
    lda #$65C0
    sta a:$2116
    lda a:$0E94
    sta $42
    lda a:$0E96
    sta $52
    lda a:$0E9C
    sta $62
    lda a:$0E9E
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
    bne upload_first_boss_normal_tiles_c19efa
upload_first_boss_normal_tiles_c19ef7:
    brl upload_first_boss_auxiliary_tiles
upload_first_boss_normal_tiles_c19efa:
    dex
    beq upload_first_boss_normal_tiles_c19ef7
    .a16
    lda #$6600
    sta a:$2116
    lda a:$0EA0
    sta $42
    lda a:$0EA2
    sta $52
    lda a:$0EA8
    sta $62
    lda a:$0EAA
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
    lda #$6700
    sta a:$2116
    lda a:$0EA4
    sta $42
    lda a:$0EA6
    sta $52
    lda a:$0EAC
    sta $62
    lda a:$0EAE
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
    bne upload_first_boss_normal_tiles_c19f55
upload_first_boss_normal_tiles_c19f52:
    brl upload_first_boss_auxiliary_tiles
upload_first_boss_normal_tiles_c19f55:
    dex
    beq upload_first_boss_normal_tiles_c19f52
    .a16
    lda #$6640
    sta a:$2116
    lda a:$0EB0
    sta $42
    lda a:$0EB2
    sta $52
    lda a:$0EB8
    sta $62
    lda a:$0EBA
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
    lda #$6740
    sta a:$2116
    lda a:$0EB4
    sta $42
    lda a:$0EB6
    sta $52
    lda a:$0EBC
    sta $62
    lda a:$0EBE
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
