; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $A7B6
upload_third_boss_auxiliary_tiles:
    lda f:$7EEA84
    tax
    bne upload_third_boss_auxiliary_tiles_c1a7c0
    brl upload_third_boss_auxiliary_tiles_c1a97c
upload_third_boss_auxiliary_tiles_c1a7c0:
    .a16
    lda #$7200
    sta a:$2116
    lda a:$0E00
    sta $42
    lda a:$0E02
    sta $52
    lda a:$0E08
    sta $62
    lda a:$0E0A
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
    lda #$7300
    sta a:$2116
    lda a:$0E04
    sta $42
    lda a:$0E06
    sta $52
    lda a:$0E0C
    sta $62
    lda a:$0E0E
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
    bne upload_third_boss_auxiliary_tiles_c1a819
upload_third_boss_auxiliary_tiles_c1a816:
    brl upload_third_boss_auxiliary_tiles_c1a97c
upload_third_boss_auxiliary_tiles_c1a819:
    dex
    beq upload_third_boss_auxiliary_tiles_c1a816
    .a16
    lda #$7240
    sta a:$2116
    lda a:$0E10
    sta $42
    lda a:$0E12
    sta $52
    lda a:$0E18
    sta $62
    lda a:$0E1A
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
    lda #$7340
    sta a:$2116
    lda a:$0E14
    sta $42
    lda a:$0E16
    sta $52
    lda a:$0E1C
    sta $62
    lda a:$0E1E
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
    bne upload_third_boss_auxiliary_tiles_c1a874
upload_third_boss_auxiliary_tiles_c1a871:
    brl upload_third_boss_auxiliary_tiles_c1a97c
upload_third_boss_auxiliary_tiles_c1a874:
    dex
    beq upload_third_boss_auxiliary_tiles_c1a871
    .a16
    lda #$7280
    sta a:$2116
    lda a:$0E20
    sta $42
    lda a:$0E22
    sta $52
    lda a:$0E28
    sta $62
    lda a:$0E2A
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
    lda #$7380
    sta a:$2116
    lda a:$0E24
    sta $42
    lda a:$0E26
    sta $52
    lda a:$0E2C
    sta $62
    lda a:$0E2E
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
    bne upload_third_boss_auxiliary_tiles_c1a8cf
upload_third_boss_auxiliary_tiles_c1a8cc:
    brl upload_third_boss_auxiliary_tiles_c1a97c
upload_third_boss_auxiliary_tiles_c1a8cf:
    dex
    beq upload_third_boss_auxiliary_tiles_c1a8cc
    .a16
    lda #$72C0
    sta a:$2116
    lda a:$0E30
    sta $42
    lda a:$0E32
    sta $52
    lda a:$0E38
    sta $62
    lda a:$0E3A
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
    lda #$73C0
    sta a:$2116
    lda a:$0E34
    sta $42
    lda a:$0E36
    sta $52
    lda a:$0E3C
    sta $62
    lda a:$0E3E
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
    beq upload_third_boss_auxiliary_tiles_c1a97c
    dex
    beq upload_third_boss_auxiliary_tiles_c1a97c
upload_third_boss_auxiliary_tiles_c1a92a:
    .a16
    lda #$7400
    sta a:$2116
    lda a:$0E40
    sta $42
    lda a:$0E42
    sta $52
    lda a:$0E48
    sta $62
    lda a:$0E4A
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
    lda #$7500
    sta a:$2116
    lda a:$0E44
    sta $42
    lda a:$0E46
    sta $52
    lda a:$0E4C
    sta $62
    lda a:$0E4E
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
upload_third_boss_auxiliary_tiles_c1a97c:
    lda f:$7EEA8D
    tax
    beq upload_third_boss_auxiliary_tiles_c1a98f
    .a16
    and #$FF00
    sta f:$7EEA8D
    .i8
    ldx #$04
    brl upload_third_boss_auxiliary_tiles_c1a92a
upload_third_boss_auxiliary_tiles_c1a98f:
    pld
    rtl
