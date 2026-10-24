; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $9BA4
upload_third_hero_auxiliary_tiles:
    lda f:$7EE484
    tax
    bne upload_third_hero_auxiliary_tiles_c19bae
    brl upload_third_hero_auxiliary_tiles_c19d6a
upload_third_hero_auxiliary_tiles_c19bae:
    .a16
    lda #$78C0
    sta a:$2116
    lda a:$0D00
    sta $42
    lda a:$0D02
    sta $52
    lda a:$0D08
    sta $62
    lda a:$0D0A
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
    lda #$79C0
    sta a:$2116
    lda a:$0D04
    sta $42
    lda a:$0D06
    sta $52
    lda a:$0D0C
    sta $62
    lda a:$0D0E
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
    bne upload_third_hero_auxiliary_tiles_c19c07
upload_third_hero_auxiliary_tiles_c19c04:
    brl upload_third_hero_auxiliary_tiles_c19d6a
upload_third_hero_auxiliary_tiles_c19c07:
    dex
    beq upload_third_hero_auxiliary_tiles_c19c04
    .a16
    lda #$7A00
    sta a:$2116
    lda a:$0D10
    sta $42
    lda a:$0D12
    sta $52
    lda a:$0D18
    sta $62
    lda a:$0D1A
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
    lda #$7B00
    sta a:$2116
    lda a:$0D14
    sta $42
    lda a:$0D16
    sta $52
    lda a:$0D1C
    sta $62
    lda a:$0D1E
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
    bne upload_third_hero_auxiliary_tiles_c19c62
upload_third_hero_auxiliary_tiles_c19c5f:
    brl upload_third_hero_auxiliary_tiles_c19d6a
upload_third_hero_auxiliary_tiles_c19c62:
    dex
    beq upload_third_hero_auxiliary_tiles_c19c5f
    .a16
    lda #$7A40
    sta a:$2116
    lda a:$0D20
    sta $42
    lda a:$0D22
    sta $52
    lda a:$0D28
    sta $62
    lda a:$0D2A
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
    lda #$7B40
    sta a:$2116
    lda a:$0D24
    sta $42
    lda a:$0D26
    sta $52
    lda a:$0D2C
    sta $62
    lda a:$0D2E
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
    bne upload_third_hero_auxiliary_tiles_c19cbd
upload_third_hero_auxiliary_tiles_c19cba:
    brl upload_third_hero_auxiliary_tiles_c19d6a
upload_third_hero_auxiliary_tiles_c19cbd:
    dex
    beq upload_third_hero_auxiliary_tiles_c19cba
    .a16
    lda #$7A80
    sta a:$2116
    lda a:$0D30
    sta $42
    lda a:$0D32
    sta $52
    lda a:$0D38
    sta $62
    lda a:$0D3A
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
    lda #$7B80
    sta a:$2116
    lda a:$0D34
    sta $42
    lda a:$0D36
    sta $52
    lda a:$0D3C
    sta $62
    lda a:$0D3E
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
    beq upload_third_hero_auxiliary_tiles_c19d6a
    dex
    beq upload_third_hero_auxiliary_tiles_c19d6a
upload_third_hero_auxiliary_tiles_c19d18:
    .a16
    lda #$7AC0
    sta a:$2116
    lda a:$0D40
    sta $42
    lda a:$0D42
    sta $52
    lda a:$0D48
    sta $62
    lda a:$0D4A
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
    lda #$7BC0
    sta a:$2116
    lda a:$0D44
    sta $42
    lda a:$0D46
    sta $52
    lda a:$0D4C
    sta $62
    lda a:$0D4E
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
upload_third_hero_auxiliary_tiles_c19d6a:
    lda f:$7EE48D
    tax
    beq upload_third_hero_auxiliary_tiles_c19d7d
    .a16
    and #$FF00
    sta f:$7EE48D
    .i8
    ldx #$04
    brl upload_third_hero_auxiliary_tiles_c19d18
upload_third_hero_auxiliary_tiles_c19d7d:
    pld
    rtl
