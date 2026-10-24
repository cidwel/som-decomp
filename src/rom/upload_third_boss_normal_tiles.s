; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

upload_third_boss_auxiliary_tiles = $A7B6

.segment "CODE"
.org $A58B
upload_third_boss_normal_tiles:
    lda f:$7EEA83
    tax
    bne upload_third_boss_normal_tiles_c1a595
    brl upload_third_boss_auxiliary_tiles
upload_third_boss_normal_tiles_c1a595:
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
    lda f:$7EEA82
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
    bne upload_third_boss_normal_tiles_c1a5f5
upload_third_boss_normal_tiles_c1a5f2:
    brl upload_third_boss_auxiliary_tiles
upload_third_boss_normal_tiles_c1a5f5:
    dex
    beq upload_third_boss_normal_tiles_c1a5f2
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
    dex
    bne upload_third_boss_normal_tiles_c1a650
upload_third_boss_normal_tiles_c1a64d:
    brl upload_third_boss_auxiliary_tiles
upload_third_boss_normal_tiles_c1a650:
    dex
    beq upload_third_boss_normal_tiles_c1a64d
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
    bne upload_third_boss_normal_tiles_c1a6ab
upload_third_boss_normal_tiles_c1a6a8:
    brl upload_third_boss_auxiliary_tiles
upload_third_boss_normal_tiles_c1a6ab:
    dex
    beq upload_third_boss_normal_tiles_c1a6a8
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
    dex
    bne upload_third_boss_normal_tiles_c1a706
upload_third_boss_normal_tiles_c1a703:
    brl upload_third_boss_auxiliary_tiles
upload_third_boss_normal_tiles_c1a706:
    dex
    beq upload_third_boss_normal_tiles_c1a703
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
    bne upload_third_boss_normal_tiles_c1a761
upload_third_boss_normal_tiles_c1a75e:
    brl upload_third_boss_auxiliary_tiles
upload_third_boss_normal_tiles_c1a761:
    dex
    beq upload_third_boss_normal_tiles_c1a75e
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
