; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

multiply_boss_terrain_row_stride = $2AA6
set_boss_object_blocked_direction = $1706

.segment "CODE"
.org $16B6
probe_boss_object_terrain_boundary:
    lda $6E
    lsr
    lsr
    lsr
    lsr
    sta $46
    .a16
    lda #$0080
    sta $4E
    sep #$20
    jsr multiply_boss_terrain_row_stride
    rep #$20
    lda $6C
    lsr
    lsr
    lsr
    lsr
    clc
    adc $56
    tay
    lda [$79],Y
    .a16
    and #$00FF
    asl
    asl
    tay
    lda [$7C],Y
    ora a:$000B,X
    .a16
    and #$0003
    .a16
    cmp #$0003
    beq probe_boss_object_terrain_boundary_c216f7
    iny
    iny
    lda [$7C],Y
    .a16
    and #$00F0
    .a16
    cmp #$0010
    beq probe_boss_object_terrain_boundary_c216f7
    clc
    rts
probe_boss_object_terrain_boundary_c216f7:
    lda $70
    ora a:$005B,X
    sta a:$005B,X
    jsr set_boss_object_blocked_direction
    ldx $87
    sec
    rts
