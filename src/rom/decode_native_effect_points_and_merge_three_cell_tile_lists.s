; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-visual-effect-point-tiles.md.
.setcpu "65816"
.smart
.a8
.i16

routine_01924c = $1924C

.segment "CODE"
.org $F9F1
decode_native_effect_points_and_merge_three_cell_tile_lists:
decode_native_effect_points_and_merge_three_cell_tile_lists_c0f9f1:
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
    bcc decode_native_effect_points_and_merge_three_cell_tile_lists_c0fa15
    bit $05
    bvs decode_native_effect_points_and_merge_three_cell_tile_lists_c0fa0c
    ror
decode_native_effect_points_and_merge_three_cell_tile_lists_c0fa0c:
    clc
    adc $0B
    bit $02
    bmi decode_native_effect_points_and_merge_three_cell_tile_lists_c0fa21
    bpl decode_native_effect_points_and_merge_three_cell_tile_lists_c0fa26
decode_native_effect_points_and_merge_three_cell_tile_lists_c0fa15:
    bit $05
    bvs decode_native_effect_points_and_merge_three_cell_tile_lists_c0fa1a
    lsr
decode_native_effect_points_and_merge_three_cell_tile_lists_c0fa1a:
    clc
    adc $0B
    bit $02
    bpl decode_native_effect_points_and_merge_three_cell_tile_lists_c0fa26
decode_native_effect_points_and_merge_three_cell_tile_lists_c0fa21:
    clc
    .a8
    adc #$0F
    .a8
    eor #$FF
decode_native_effect_points_and_merge_three_cell_tile_lists_c0fa26:
    xba
    bpl decode_native_effect_points_and_merge_three_cell_tile_lists_c0fa38
    bit $05
    bvs decode_native_effect_points_and_merge_three_cell_tile_lists_c0fa2f
    sec
    ror
decode_native_effect_points_and_merge_three_cell_tile_lists_c0fa2f:
    clc
    adc $0A
    bit $02
    bvs decode_native_effect_points_and_merge_three_cell_tile_lists_c0fa44
    bvc decode_native_effect_points_and_merge_three_cell_tile_lists_c0fa49
decode_native_effect_points_and_merge_three_cell_tile_lists_c0fa38:
    bit $05
    bvs decode_native_effect_points_and_merge_three_cell_tile_lists_c0fa3d
    lsr
decode_native_effect_points_and_merge_three_cell_tile_lists_c0fa3d:
    clc
    adc $0A
    bit $02
    bvc decode_native_effect_points_and_merge_three_cell_tile_lists_c0fa49
decode_native_effect_points_and_merge_three_cell_tile_lists_c0fa44:
    clc
    .a8
    adc #$0F
    .a8
    eor #$FF
decode_native_effect_points_and_merge_three_cell_tile_lists_c0fa49:
    rep #$20
    sta a:$C000,X
    sep #$20
    lda $01
    eor $02
    .a8
    and #$C0
    ora $0D
    sta a:$C003,X
    lda $0C
    sta a:$C002,X
    clc
    .a8
    adc #$02
    .a8
    bit #$10
    beq decode_native_effect_points_and_merge_three_cell_tile_lists_c0fa6d
    .a8
    adc #$10
    bcc decode_native_effect_points_and_merge_three_cell_tile_lists_c0fa6d
    inc $0D
decode_native_effect_points_and_merge_three_cell_tile_lists_c0fa6d:
    sta $0C
    inx
    inx
    inx
    inx
    dey
    beq decode_native_effect_points_and_merge_three_cell_tile_lists_c0fa79
    brl decode_native_effect_points_and_merge_three_cell_tile_lists_c0f9f1
decode_native_effect_points_and_merge_three_cell_tile_lists_c0fa79:
    ldx $14
    sep #$20
    lda a:$E110,X
    .a8
    cmp #$04
    beq decode_native_effect_points_and_merge_three_cell_tile_lists_c0fa87
    brl decode_native_effect_points_and_merge_three_cell_tile_lists_c0fb83
decode_native_effect_points_and_merge_three_cell_tile_lists_c0fa87:
    lda a:$E084,X
    asl
    asl
    sta a:$E113,X
    rep #$20
    .a16
    and #$007F
    sta $00
    phx
    txa
    lsr
    sta $02
    ldy a:$E06C,X
    lda a:$E11C,X
    asl
    ora $02
    tax
decode_native_effect_points_and_merge_three_cell_tile_lists_c0faa5:
    lda a:$0000,Y
    sta a:$C060,X
    inx
    inx
    iny
    iny
    dec $00
    bne decode_native_effect_points_and_merge_three_cell_tile_lists_c0faa5
    plx
    phx
    lda a:$E123,X
    .a16
    and #$007F
    sta $00
    lda a:$E12C,X
    asl
    ora $02
    tax
decode_native_effect_points_and_merge_three_cell_tile_lists_c0fac4:
    lda a:$C060,X
    sta a:$0000,Y
    iny
    iny
    inx
    inx
    dec $00
    bne decode_native_effect_points_and_merge_three_cell_tile_lists_c0fac4
    plx
    phx
    lda a:$E133,X
    .a16
    and #$007F
    sta $00
    lda a:$E13C,X
    asl
    ora $02
    tax
decode_native_effect_points_and_merge_three_cell_tile_lists_c0fae3:
    lda a:$C060,X
    sta a:$0000,Y
    iny
    iny
    inx
    inx
    dec $00
    bne decode_native_effect_points_and_merge_three_cell_tile_lists_c0fae3
    plx
    sep #$20
    lda a:$E113,X
    clc
    adc a:$E123,X
    adc a:$E133,X
    lsr
    lsr
    sta a:$E084,X
    rep #$20
    lda a:$E113,X
    .a16
    and #$007F
    dec
    dec
    clc
    adc a:$E11C,X
    ora $02
    tay
    lda a:$C000,Y
    .a16
    and #$01FF
    sta $04
    lda a:$E123,X
    .a16
    and #$007F
    lsr
    lsr
    sta $00
    lda a:$E12C,X
    ora $02
    tay
decode_native_effect_points_and_merge_three_cell_tile_lists_c0fb2c:
    lda $04
    clc
    .a16
    adc #$0002
    .a16
    bit #$0010
    beq decode_native_effect_points_and_merge_three_cell_tile_lists_c0fb3a
    .a16
    adc #$0010
decode_native_effect_points_and_merge_three_cell_tile_lists_c0fb3a:
    sta $04
    lda a:$C002,Y
    .a16
    and #$FE00
    ora $04
    sta a:$C002,Y
    iny
    iny
    iny
    iny
    dec $00
    bne decode_native_effect_points_and_merge_three_cell_tile_lists_c0fb2c
    lda a:$E133,X
    .a16
    and #$007F
    lsr
    lsr
    sta $00
    lda a:$E13C,X
    ora $02
    tay
decode_native_effect_points_and_merge_three_cell_tile_lists_c0fb5f:
    lda $04
    clc
    .a16
    adc #$0002
    .a16
    bit #$0010
    beq decode_native_effect_points_and_merge_three_cell_tile_lists_c0fb6d
    .a16
    adc #$0010
decode_native_effect_points_and_merge_three_cell_tile_lists_c0fb6d:
    sta $04
    lda a:$C002,Y
    .a16
    and #$FE00
    ora $04
    sta a:$C002,Y
    iny
    iny
    iny
    iny
    dec $00
    bne decode_native_effect_points_and_merge_three_cell_tile_lists_c0fb5f
decode_native_effect_points_and_merge_three_cell_tile_lists_c0fb82:
    rts
decode_native_effect_points_and_merge_three_cell_tile_lists_c0fb83:
    bcs decode_native_effect_points_and_merge_three_cell_tile_lists_c0fb8e
    .a8
    cmp #$01
    beq decode_native_effect_points_and_merge_three_cell_tile_lists_c0fb82
    jsl f:routine_01924c
    rts
decode_native_effect_points_and_merge_three_cell_tile_lists_c0fb8e:
    rts
