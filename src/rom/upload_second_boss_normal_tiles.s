; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

upload_second_boss_auxiliary_tiles = $A3B0

.segment "CODE"
.org $A185
upload_second_boss_normal_tiles:
    lda f:$7EE883
    tax
    bne upload_second_boss_normal_tiles_c1a18f
    brl upload_second_boss_auxiliary_tiles
upload_second_boss_normal_tiles_c1a18f:
    .a16
    lda #$6680
    sta a:$2116
    lda a:$0EC0
    sta $42
    lda a:$0EC2
    sta $52
    lda a:$0EC8
    sta $62
    lda a:$0ECA
    sta $72
    lda f:$7EE882
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
    lda #$6780
    sta a:$2116
    lda a:$0EC4
    sta $42
    lda a:$0EC6
    sta $52
    lda a:$0ECC
    sta $62
    lda a:$0ECE
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
    bne upload_second_boss_normal_tiles_c1a1ef
upload_second_boss_normal_tiles_c1a1ec:
    brl upload_second_boss_auxiliary_tiles
upload_second_boss_normal_tiles_c1a1ef:
    dex
    beq upload_second_boss_normal_tiles_c1a1ec
    .a16
    lda #$66C0
    sta a:$2116
    lda a:$0ED0
    sta $42
    lda a:$0ED2
    sta $52
    lda a:$0ED8
    sta $62
    lda a:$0EDA
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
    lda #$67C0
    sta a:$2116
    lda a:$0ED4
    sta $42
    lda a:$0ED6
    sta $52
    lda a:$0EDC
    sta $62
    lda a:$0EDE
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
    bne upload_second_boss_normal_tiles_c1a24a
upload_second_boss_normal_tiles_c1a247:
    brl upload_second_boss_auxiliary_tiles
upload_second_boss_normal_tiles_c1a24a:
    dex
    beq upload_second_boss_normal_tiles_c1a247
    .a16
    lda #$6800
    sta a:$2116
    lda a:$0EE0
    sta $42
    lda a:$0EE2
    sta $52
    lda a:$0EE8
    sta $62
    lda a:$0EEA
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
    lda #$6900
    sta a:$2116
    lda a:$0EE4
    sta $42
    lda a:$0EE6
    sta $52
    lda a:$0EEC
    sta $62
    lda a:$0EEE
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
    bne upload_second_boss_normal_tiles_c1a2a5
upload_second_boss_normal_tiles_c1a2a2:
    brl upload_second_boss_auxiliary_tiles
upload_second_boss_normal_tiles_c1a2a5:
    dex
    beq upload_second_boss_normal_tiles_c1a2a2
    .a16
    lda #$6840
    sta a:$2116
    lda a:$0EF0
    sta $42
    lda a:$0EF2
    sta $52
    lda a:$0EF8
    sta $62
    lda a:$0EFA
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
    lda #$6940
    sta a:$2116
    lda a:$0EF4
    sta $42
    lda a:$0EF6
    sta $52
    lda a:$0EFC
    sta $62
    lda a:$0EFE
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
    bne upload_second_boss_normal_tiles_c1a300
upload_second_boss_normal_tiles_c1a2fd:
    brl upload_second_boss_auxiliary_tiles
upload_second_boss_normal_tiles_c1a300:
    dex
    beq upload_second_boss_normal_tiles_c1a2fd
    .a16
    lda #$6880
    sta a:$2116
    lda a:$0F00
    sta $42
    lda a:$0F02
    sta $52
    lda a:$0F08
    sta $62
    lda a:$0F0A
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
    lda #$6980
    sta a:$2116
    lda a:$0F04
    sta $42
    lda a:$0F06
    sta $52
    lda a:$0F0C
    sta $62
    lda a:$0F0E
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
    bne upload_second_boss_normal_tiles_c1a35b
upload_second_boss_normal_tiles_c1a358:
    brl upload_second_boss_auxiliary_tiles
upload_second_boss_normal_tiles_c1a35b:
    dex
    beq upload_second_boss_normal_tiles_c1a358
    .a16
    lda #$68C0
    sta a:$2116
    lda a:$0F10
    sta $42
    lda a:$0F12
    sta $52
    lda a:$0F18
    sta $62
    lda a:$0F1A
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
    lda #$69C0
    sta a:$2116
    lda a:$0F14
    sta $42
    lda a:$0F16
    sta $52
    lda a:$0F1C
    sta $62
    lda a:$0F1E
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
