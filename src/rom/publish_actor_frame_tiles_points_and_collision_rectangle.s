; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-visual-frame-geometry.md.
.setcpu "65816"
.smart
.a8
.i16

decode_native_effect_points_and_merge_three_cell_tile_lists = $F9F1
routine_01818f = $1818F
routine_02a480 = $2A480
routine_02abca = $2ABCA

.segment "CODE"
.org $F1CF
publish_actor_frame_tiles_points_and_collision_rectangle:
    sep #$20
    rep #$10
    stx $14
    lda a:$E02F,X
    bne publish_actor_frame_tiles_points_and_collision_rectangle_c0f21b
    lda a:$E060,X
    beq publish_actor_frame_tiles_points_and_collision_rectangle_c0f210
    bit $ED
    bmi publish_actor_frame_tiles_points_and_collision_rectangle_c0f1e8
    .i16
    cpx #$0600
    bcs publish_actor_frame_tiles_points_and_collision_rectangle_c0f20c
publish_actor_frame_tiles_points_and_collision_rectangle_c0f1e8:
    .a8
    cmp #$20
    beq publish_actor_frame_tiles_points_and_collision_rectangle_c0f21b
    jsl f:routine_01818f
    sep #$20
    .a8
    lda #$D4
    sta $12
    lda a:$E060,X
    .a8
    and #$E0
    bpl publish_actor_frame_tiles_points_and_collision_rectangle_c0f207
    dec $12
    .a8
    cmp #$C0
    bcs publish_actor_frame_tiles_points_and_collision_rectangle_c0f207
    .a8
    lda #$D0
    sta $12
publish_actor_frame_tiles_points_and_collision_rectangle_c0f207:
    lda a:$E00C,X
    bne publish_actor_frame_tiles_points_and_collision_rectangle_c0f224
publish_actor_frame_tiles_points_and_collision_rectangle_c0f20c:
    stz a:$E00C,X
    rts
publish_actor_frame_tiles_points_and_collision_rectangle_c0f210:
    lda a:$E191,X
    .a8
    bit #$C5
    bne publish_actor_frame_tiles_points_and_collision_rectangle_c0f21b
    bit $ED
    bpl publish_actor_frame_tiles_points_and_collision_rectangle_c0f20c
publish_actor_frame_tiles_points_and_collision_rectangle_c0f21b:
    lda a:$E00C,X
    beq publish_actor_frame_tiles_points_and_collision_rectangle_c0f20c
    .a8
    lda #$D4
    sta $12
publish_actor_frame_tiles_points_and_collision_rectangle_c0f224:
    stz a:$E00C,X
    rep #$20
    clc
    lda a:$E06A,X
    adc a:$E026,X
    sta $10
    lda [$10]
    sta $10
    txa
    asl
    asl
    asl
    clc
    .a16
    adc #$2000
    sta $0A
    ldy a:$E06C,X
    sep #$20
    stz $01
    lda [$10]
    inc $10
    bne publish_actor_frame_tiles_points_and_collision_rectangle_c0f24f
    inc $11
publish_actor_frame_tiles_points_and_collision_rectangle_c0f24f:
    sta a:$E024,X
    sta $04
    asl
    asl
    sta $05
    lda $04
    .a8
    and #$0F
    sta a:$E084,X
    bne publish_actor_frame_tiles_points_and_collision_rectangle_c0f276
    lda a:$E074,X
    .a8
    and #$7F
    sta $03
    lda a:$E028,X
    .a8
    and #$C0
    sta $02
    brl publish_actor_frame_tiles_points_and_collision_rectangle_c0f409
publish_actor_frame_tiles_points_and_collision_rectangle_c0f272:
    stz a:$E084,X
    rts
publish_actor_frame_tiles_points_and_collision_rectangle_c0f276:
    .a8
    cmp #$0B
    bcs publish_actor_frame_tiles_points_and_collision_rectangle_c0f272
    asl
    asl
    sta $00
    rep #$20
    ldx $00
publish_actor_frame_tiles_points_and_collision_rectangle_c0f282:
    lda [$10]
    .a16
    bit #$0080
    bne publish_actor_frame_tiles_points_and_collision_rectangle_c0f2a8
    inc $10
    xba
    .a16
    and #$7F00
    .a16
    cmp #$7F00
    bne publish_actor_frame_tiles_points_and_collision_rectangle_c0f299
    .a16
    lda #$CB00
    bra publish_actor_frame_tiles_points_and_collision_rectangle_c0f29e
publish_actor_frame_tiles_points_and_collision_rectangle_c0f299:
    lsr
    lsr
    lsr
    adc $0A
publish_actor_frame_tiles_points_and_collision_rectangle_c0f29e:
    sta a:$0000,Y
    iny
    iny
    dex
    bne publish_actor_frame_tiles_points_and_collision_rectangle_c0f282
    beq publish_actor_frame_tiles_points_and_collision_rectangle_c0f2f9
publish_actor_frame_tiles_points_and_collision_rectangle_c0f2a8:
    inc $10
    inc $10
    .a16
    bit #$0040
    beq publish_actor_frame_tiles_points_and_collision_rectangle_c0f2d2
    pha
    .a16
    and #$003F
    sta $02
    pla
    .a16
    and #$7F00
    lsr
    lsr
    lsr
    adc $0A
publish_actor_frame_tiles_points_and_collision_rectangle_c0f2c0:
    sta a:$0000,Y
    iny
    iny
    dex
    beq publish_actor_frame_tiles_points_and_collision_rectangle_c0f2f9
    dec $02
    bmi publish_actor_frame_tiles_points_and_collision_rectangle_c0f282
    clc
    .a16
    adc #$0020
    bra publish_actor_frame_tiles_points_and_collision_rectangle_c0f2c0
publish_actor_frame_tiles_points_and_collision_rectangle_c0f2d2:
    pha
    .a16
    and #$003F
    sta $02
    pla
    .a16
    and #$7F00
    .a16
    cmp #$7F00
    bne publish_actor_frame_tiles_points_and_collision_rectangle_c0f2e6
    .a16
    lda #$CB00
    bra publish_actor_frame_tiles_points_and_collision_rectangle_c0f2eb
publish_actor_frame_tiles_points_and_collision_rectangle_c0f2e6:
    lsr
    lsr
    lsr
    adc $0A
publish_actor_frame_tiles_points_and_collision_rectangle_c0f2eb:
    sta a:$0000,Y
    iny
    iny
    dex
    beq publish_actor_frame_tiles_points_and_collision_rectangle_c0f2f9
    dec $02
    bpl publish_actor_frame_tiles_points_and_collision_rectangle_c0f2eb
    bmi publish_actor_frame_tiles_points_and_collision_rectangle_c0f282
publish_actor_frame_tiles_points_and_collision_rectangle_c0f2f9:
    rep #$30
    ldx $14
    lda a:$E084,X
    .a16
    and #$000F
    tay
    sta $06
    lda a:$E028,X
    .a16
    and #$00C0
    sta $02
    lda a:$E086,X
    sta $0C
    sep #$20
    lda a:$E093,X
    .a8
    and #$30
    ora $0D
    sta $0D
    lda a:$E074,X
    .a8
    and #$7F
    sta $03
    lda a:$E025,X
    bne publish_actor_frame_tiles_points_and_collision_rectangle_c0f32e
    sta $0A
    bra publish_actor_frame_tiles_points_and_collision_rectangle_c0f344
publish_actor_frame_tiles_points_and_collision_rectangle_c0f32e:
    pha
    .a8
    and #$0F
    .a8
    cmp #$08
    bcc publish_actor_frame_tiles_points_and_collision_rectangle_c0f337
    .a8
    ora #$F0
publish_actor_frame_tiles_points_and_collision_rectangle_c0f337:
    sta $0A
    pla
    lsr
    lsr
    lsr
    lsr
    .a8
    cmp #$08
    bcc publish_actor_frame_tiles_points_and_collision_rectangle_c0f344
    .a8
    ora #$F0
publish_actor_frame_tiles_points_and_collision_rectangle_c0f344:
    sta $0B
    lda a:$E060,X
    beq publish_actor_frame_tiles_points_and_collision_rectangle_c0f381
    pha
    .a8
    lda #$30
    tsb $0D
    pla
    .a8
    cmp #$E0
    bne publish_actor_frame_tiles_points_and_collision_rectangle_c0f36d
    lda a:$E110,X
    .a8
    cmp #$04
    bne publish_actor_frame_tiles_points_and_collision_rectangle_c0f365
    rep #$20
    txa
    lsr
    ora a:$E11C,X
    bra publish_actor_frame_tiles_points_and_collision_rectangle_c0f369
publish_actor_frame_tiles_points_and_collision_rectangle_c0f365:
    rep #$20
    txa
    lsr
publish_actor_frame_tiles_points_and_collision_rectangle_c0f369:
    tax
    brl decode_native_effect_points_and_merge_three_cell_tile_lists
publish_actor_frame_tiles_points_and_collision_rectangle_c0f36d:
    .a8
    cmp #$C0
    bne publish_actor_frame_tiles_points_and_collision_rectangle_c0f381
    bit $05
    bpl publish_actor_frame_tiles_points_and_collision_rectangle_c0f381
    lda a:$E110,X
    .a8
    cmp #$05
    bne publish_actor_frame_tiles_points_and_collision_rectangle_c0f381
    jsl f:routine_02abca
    rts
publish_actor_frame_tiles_points_and_collision_rectangle_c0f381:
    rep #$20
    lda [$10]
    inc $10
    inc $10
    sep #$20
    xba
    asl
    ror $01
    xba
    asl
    ror $01
    .a8
    cmp #$80
    bcc publish_actor_frame_tiles_points_and_collision_rectangle_c0f3a5
    bit $05
    bvs publish_actor_frame_tiles_points_and_collision_rectangle_c0f39c
    ror
publish_actor_frame_tiles_points_and_collision_rectangle_c0f39c:
    clc
    adc $0B
    bit $02
    bmi publish_actor_frame_tiles_points_and_collision_rectangle_c0f3b1
    bpl publish_actor_frame_tiles_points_and_collision_rectangle_c0f3b6
publish_actor_frame_tiles_points_and_collision_rectangle_c0f3a5:
    bit $05
    bvs publish_actor_frame_tiles_points_and_collision_rectangle_c0f3aa
    lsr
publish_actor_frame_tiles_points_and_collision_rectangle_c0f3aa:
    clc
    adc $0B
    bit $02
    bpl publish_actor_frame_tiles_points_and_collision_rectangle_c0f3b6
publish_actor_frame_tiles_points_and_collision_rectangle_c0f3b1:
    clc
    .a8
    adc #$0F
    .a8
    eor #$FF
publish_actor_frame_tiles_points_and_collision_rectangle_c0f3b6:
    xba
    bpl publish_actor_frame_tiles_points_and_collision_rectangle_c0f3c8
    bit $05
    bvs publish_actor_frame_tiles_points_and_collision_rectangle_c0f3bf
    sec
    ror
publish_actor_frame_tiles_points_and_collision_rectangle_c0f3bf:
    clc
    adc $0A
    bit $02
    bvs publish_actor_frame_tiles_points_and_collision_rectangle_c0f3d4
    bvc publish_actor_frame_tiles_points_and_collision_rectangle_c0f3d9
publish_actor_frame_tiles_points_and_collision_rectangle_c0f3c8:
    bit $05
    bvs publish_actor_frame_tiles_points_and_collision_rectangle_c0f3cd
    lsr
publish_actor_frame_tiles_points_and_collision_rectangle_c0f3cd:
    clc
    adc $0A
    bit $02
    bvc publish_actor_frame_tiles_points_and_collision_rectangle_c0f3d9
publish_actor_frame_tiles_points_and_collision_rectangle_c0f3d4:
    clc
    .a8
    adc #$0F
    .a8
    eor #$FF
publish_actor_frame_tiles_points_and_collision_rectangle_c0f3d9:
    rep #$20
    sta a:$E0D0,X
    sep #$20
    lda $01
    eor $02
    .a8
    and #$C0
    ora $0D
    sta a:$E0D3,X
    lda $0C
    sta a:$E0D2,X
    clc
    .a8
    adc #$02
    .a8
    bit #$10
    beq publish_actor_frame_tiles_points_and_collision_rectangle_c0f3fd
    .a8
    adc #$10
    bcc publish_actor_frame_tiles_points_and_collision_rectangle_c0f3fd
    inc $0D
publish_actor_frame_tiles_points_and_collision_rectangle_c0f3fd:
    sta $0C
    inx
    inx
    inx
    inx
    dey
    beq publish_actor_frame_tiles_points_and_collision_rectangle_c0f409
    brl publish_actor_frame_tiles_points_and_collision_rectangle_c0f381
publish_actor_frame_tiles_points_and_collision_rectangle_c0f409:
    sep #$20
    ldx $14
    lda a:$E060,X
    beq publish_actor_frame_tiles_points_and_collision_rectangle_c0f42c
    .a8
    cmp #$C0
    bne publish_actor_frame_tiles_points_and_collision_rectangle_c0f423
    stz a:$E114,X
    bit $05
    bpl publish_actor_frame_tiles_points_and_collision_rectangle_c0f423
    jsl f:routine_02a480
    sep #$20
publish_actor_frame_tiles_points_and_collision_rectangle_c0f423:
    .a8
    lda #$00
    sta a:$E0C2,X
    sta a:$E0C3,X
    rts
publish_actor_frame_tiles_points_and_collision_rectangle_c0f42c:
    bit $04
    bvc publish_actor_frame_tiles_points_and_collision_rectangle_c0f423
    .i16
    ldy #$0001
    .a8
    lda #$10
    bit $04
    beq publish_actor_frame_tiles_points_and_collision_rectangle_c0f460
    lda [$10]
    bit $02
    bpl publish_actor_frame_tiles_points_and_collision_rectangle_c0f442
    .a8
    eor #$FF
    inc
publish_actor_frame_tiles_points_and_collision_rectangle_c0f442:
    sec
    sbc $03
    sbc a:$E045,X
    bvc publish_actor_frame_tiles_points_and_collision_rectangle_c0f44c
    .a8
    lda #$80
publish_actor_frame_tiles_points_and_collision_rectangle_c0f44c:
    sta a:$E0C1,X
    lda [$10],Y
    bit $02
    bvc publish_actor_frame_tiles_points_and_collision_rectangle_c0f458
    .a8
    eor #$FF
    inc
publish_actor_frame_tiles_points_and_collision_rectangle_c0f458:
    sta a:$E0C0,X
    iny
    lda [$10],Y
    bra publish_actor_frame_tiles_points_and_collision_rectangle_c0f49a
publish_actor_frame_tiles_points_and_collision_rectangle_c0f460:
    lda [$10]
    pha
    .a8
    and #$0F
    .a8
    cmp #$08
    bcc publish_actor_frame_tiles_points_and_collision_rectangle_c0f46b
    .a8
    ora #$F0
publish_actor_frame_tiles_points_and_collision_rectangle_c0f46b:
    asl
    asl
    bit $02
    bvc publish_actor_frame_tiles_points_and_collision_rectangle_c0f474
    .a8
    eor #$FF
    inc
publish_actor_frame_tiles_points_and_collision_rectangle_c0f474:
    sta a:$E0C0,X
    pla
    lsr
    lsr
    lsr
    lsr
    .a8
    cmp #$08
    bcc publish_actor_frame_tiles_points_and_collision_rectangle_c0f482
    .a8
    ora #$F0
publish_actor_frame_tiles_points_and_collision_rectangle_c0f482:
    asl
    asl
    bit $02
    bpl publish_actor_frame_tiles_points_and_collision_rectangle_c0f48b
    .a8
    eor #$FF
    inc
publish_actor_frame_tiles_points_and_collision_rectangle_c0f48b:
    sec
    sbc $03
    sbc a:$E045,X
    bvc publish_actor_frame_tiles_points_and_collision_rectangle_c0f495
    .a8
    lda #$80
publish_actor_frame_tiles_points_and_collision_rectangle_c0f495:
    sta a:$E0C1,X
    lda [$10],Y
publish_actor_frame_tiles_points_and_collision_rectangle_c0f49a:
    pha
    .a8
    and #$0F
    asl
    asl
    sta a:$E0C2,X
    pla
    lsr
    lsr
    .a8
    and #$3C
    sta a:$E0C3,X
    rts
