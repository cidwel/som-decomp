; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

probe_boss_object_terrain_boundary = $16B6
read_boss_object_terrain_layer = $1683

.segment "CODE"
.org $15B7
prepare_boss_object_terrain:
    lda a:$0098,X
    sta $8D
    lda a:$002B,X
    cmp a:$00C0
    bcs prepare_boss_object_terrain_c215d2
    sta $3C
    lda a:$0032,X
    clc
    adc a:$00A5,X
    cmp a:$00C2
    bcc prepare_boss_object_terrain_c215d3
prepare_boss_object_terrain_c215d2:
    rts
prepare_boss_object_terrain_c215d3:
    sta $3E
    lda a:$001E,X
    asl
    tax
    lda f:$D97EE5,X
    .a16
    and #$00FF
    sta $40
    lda f:$D97EE6,X
    .a16
    and #$00FF
    sta $42
    .a16
    lda #$7F00
    sta $7A
    sta $7D
    .a16
    lda #$0000
    sta $79
    .a16
    lda #$B800
    sta $7C
    lda $8D
    .a16
    bit #$0002
    beq prepare_boss_object_terrain_c21614
    .a16
    lda #$4000
    clc
    adc $79
    sta $79
    .a16
    lda #$0400
    clc
    adc $7C
    sta $7C
prepare_boss_object_terrain_c21614:
    lda a:$E00B
    bpl prepare_boss_object_terrain_c21629
    lda $79
    clc
    .a16
    adc #$4000
    sta $79
    lda $7C
    clc
    .a16
    adc #$0400
    sta $7C
prepare_boss_object_terrain_c21629:
    ldx $87
    jsr read_boss_object_terrain_layer
    clc
    lda $8D
    .a16
    bit #$0400
    beq prepare_boss_object_terrain_c21680
    .a16
    lda #$0001
    sta $70
    lda $3C
    clc
    adc $40
    sta $6C
    lda $3E
    sta $6E
    jsr probe_boss_object_terrain_boundary
    bcs prepare_boss_object_terrain_c21680
    .a16
    lda #$0004
    sta $70
    lda $3C
    sec
    sbc $40
    sta $6C
    jsr probe_boss_object_terrain_boundary
    bcs prepare_boss_object_terrain_c21680
    .a16
    lda #$0002
    sta $70
    lda $3C
    sta $6C
    lda $3E
    clc
    adc $42
    sta $6E
    jsr probe_boss_object_terrain_boundary
    bcs prepare_boss_object_terrain_c21680
    .a16
    lda #$0008
    sta $70
    lda $3E
    sec
    sbc $42
    sta $6E
    jsr probe_boss_object_terrain_boundary
prepare_boss_object_terrain_c21680:
    ldx $87
    rts
