; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

upload_third_hero_auxiliary_tiles = $9BA4

.segment "CODE"
.org $99CB
upload_second_hero_auxiliary_tiles:
    lda f:$7EE284
    tax
    bne upload_second_hero_auxiliary_tiles_c199d5
    brl upload_second_hero_auxiliary_tiles_c19b91
upload_second_hero_auxiliary_tiles_c199d5:
    .a16
    lda #$7680
    sta a:$2116
    lda a:$0CB0
    sta $42
    lda a:$0CB2
    sta $52
    lda a:$0CB8
    sta $62
    lda a:$0CBA
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
    lda #$7780
    sta a:$2116
    lda a:$0CB4
    sta $42
    lda a:$0CB6
    sta $52
    lda a:$0CBC
    sta $62
    lda a:$0CBE
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
    bne upload_second_hero_auxiliary_tiles_c19a2e
upload_second_hero_auxiliary_tiles_c19a2b:
    brl upload_second_hero_auxiliary_tiles_c19b91
upload_second_hero_auxiliary_tiles_c19a2e:
    dex
    beq upload_second_hero_auxiliary_tiles_c19a2b
    .a16
    lda #$76C0
    sta a:$2116
    lda a:$0CC0
    sta $42
    lda a:$0CC2
    sta $52
    lda a:$0CC8
    sta $62
    lda a:$0CCA
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
    lda #$77C0
    sta a:$2116
    lda a:$0CC4
    sta $42
    lda a:$0CC6
    sta $52
    lda a:$0CCC
    sta $62
    lda a:$0CCE
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
    bne upload_second_hero_auxiliary_tiles_c19a89
upload_second_hero_auxiliary_tiles_c19a86:
    brl upload_second_hero_auxiliary_tiles_c19b91
upload_second_hero_auxiliary_tiles_c19a89:
    dex
    beq upload_second_hero_auxiliary_tiles_c19a86
    .a16
    lda #$7800
    sta a:$2116
    lda a:$0CD0
    sta $42
    lda a:$0CD2
    sta $52
    lda a:$0CD8
    sta $62
    lda a:$0CDA
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
    lda #$7900
    sta a:$2116
    lda a:$0CD4
    sta $42
    lda a:$0CD6
    sta $52
    lda a:$0CDC
    sta $62
    lda a:$0CDE
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
    bne upload_second_hero_auxiliary_tiles_c19ae4
upload_second_hero_auxiliary_tiles_c19ae1:
    brl upload_second_hero_auxiliary_tiles_c19b91
upload_second_hero_auxiliary_tiles_c19ae4:
    dex
    beq upload_second_hero_auxiliary_tiles_c19ae1
    .a16
    lda #$7840
    sta a:$2116
    lda a:$0CE0
    sta $42
    lda a:$0CE2
    sta $52
    lda a:$0CE8
    sta $62
    lda a:$0CEA
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
    lda #$7940
    sta a:$2116
    lda a:$0CE4
    sta $42
    lda a:$0CE6
    sta $52
    lda a:$0CEC
    sta $62
    lda a:$0CEE
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
    beq upload_second_hero_auxiliary_tiles_c19b91
    dex
    beq upload_second_hero_auxiliary_tiles_c19b91
upload_second_hero_auxiliary_tiles_c19b3f:
    .a16
    lda #$7880
    sta a:$2116
    lda a:$0CF0
    sta $42
    lda a:$0CF2
    sta $52
    lda a:$0CF8
    sta $62
    lda a:$0CFA
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
    lda #$7980
    sta a:$2116
    lda a:$0CF4
    sta $42
    lda a:$0CF6
    sta $52
    lda a:$0CFC
    sta $62
    lda a:$0CFE
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
upload_second_hero_auxiliary_tiles_c19b91:
    lda f:$7EE28D
    tax
    beq upload_third_hero_auxiliary_tiles
    .a16
    and #$FF00
    sta f:$7EE28D
    .i8
    ldx #$04
    brl upload_second_hero_auxiliary_tiles_c19b3f
