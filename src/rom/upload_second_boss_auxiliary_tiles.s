; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $A3B0
upload_second_boss_auxiliary_tiles:
    lda f:$7EE884
    tax
    bne upload_second_boss_auxiliary_tiles_c1a3ba
    brl upload_second_boss_auxiliary_tiles_c1a576
upload_second_boss_auxiliary_tiles_c1a3ba:
    .a16
    lda #$6EC0
    sta a:$2116
    lda a:$0DB0
    sta $42
    lda a:$0DB2
    sta $52
    lda a:$0DB8
    sta $62
    lda a:$0DBA
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
    lda #$6FC0
    sta a:$2116
    lda a:$0DB4
    sta $42
    lda a:$0DB6
    sta $52
    lda a:$0DBC
    sta $62
    lda a:$0DBE
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
    bne upload_second_boss_auxiliary_tiles_c1a413
upload_second_boss_auxiliary_tiles_c1a410:
    brl upload_second_boss_auxiliary_tiles_c1a576
upload_second_boss_auxiliary_tiles_c1a413:
    dex
    beq upload_second_boss_auxiliary_tiles_c1a410
    .a16
    lda #$7000
    sta a:$2116
    lda a:$0DC0
    sta $42
    lda a:$0DC2
    sta $52
    lda a:$0DC8
    sta $62
    lda a:$0DCA
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
    lda #$7100
    sta a:$2116
    lda a:$0DC4
    sta $42
    lda a:$0DC6
    sta $52
    lda a:$0DCC
    sta $62
    lda a:$0DCE
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
    bne upload_second_boss_auxiliary_tiles_c1a46e
upload_second_boss_auxiliary_tiles_c1a46b:
    brl upload_second_boss_auxiliary_tiles_c1a576
upload_second_boss_auxiliary_tiles_c1a46e:
    dex
    beq upload_second_boss_auxiliary_tiles_c1a46b
    .a16
    lda #$7040
    sta a:$2116
    lda a:$0DD0
    sta $42
    lda a:$0DD2
    sta $52
    lda a:$0DD8
    sta $62
    lda a:$0DDA
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
    lda #$7140
    sta a:$2116
    lda a:$0DD4
    sta $42
    lda a:$0DD6
    sta $52
    lda a:$0DDC
    sta $62
    lda a:$0DDE
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
    bne upload_second_boss_auxiliary_tiles_c1a4c9
upload_second_boss_auxiliary_tiles_c1a4c6:
    brl upload_second_boss_auxiliary_tiles_c1a576
upload_second_boss_auxiliary_tiles_c1a4c9:
    dex
    beq upload_second_boss_auxiliary_tiles_c1a4c6
    .a16
    lda #$7080
    sta a:$2116
    lda a:$0DE0
    sta $42
    lda a:$0DE2
    sta $52
    lda a:$0DE8
    sta $62
    lda a:$0DEA
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
    lda #$7180
    sta a:$2116
    lda a:$0DE4
    sta $42
    lda a:$0DE6
    sta $52
    lda a:$0DEC
    sta $62
    lda a:$0DEE
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
    beq upload_second_boss_auxiliary_tiles_c1a576
    dex
    beq upload_second_boss_auxiliary_tiles_c1a576
upload_second_boss_auxiliary_tiles_c1a524:
    .a16
    lda #$70C0
    sta a:$2116
    lda a:$0DF0
    sta $42
    lda a:$0DF2
    sta $52
    lda a:$0DF8
    sta $62
    lda a:$0DFA
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
    lda #$71C0
    sta a:$2116
    lda a:$0DF4
    sta $42
    lda a:$0DF6
    sta $52
    lda a:$0DFC
    sta $62
    lda a:$0DFE
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
upload_second_boss_auxiliary_tiles_c1a576:
    lda f:$7EE88D
    tax
    beq upload_second_boss_auxiliary_tiles_c1a589
    .a16
    and #$FF00
    sta f:$7EE88D
    .i8
    ldx #$04
    brl upload_second_boss_auxiliary_tiles_c1a524
upload_second_boss_auxiliary_tiles_c1a589:
    pld
    rtl
