; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-font-parser.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c017c7 = $17C7
routine_c018fb = $18FB
routine_c0190a = $190A

.segment "CODE"
.org $16B8
decode_dialogue_font_stream_and_all_insertion_commands:
    .i16
    ldx #$0000
    .a8
    lda #$80
decode_dialogue_font_stream_and_all_insertion_commands_c016bd:
    sta a:$A1A4,X
    inx
    .i16
    cpx #$0021
    bne decode_dialogue_font_stream_and_all_insertion_commands_c016bd
    lda a:$A16A
    sec
    sbc a:$A181
    sta a:$A1CA
    stz a:$A1CE
    lda a:$1D03
    ldy a:$1D01
    phb
    pha
    plb
    .i16
    ldx #$0000
decode_dialogue_font_stream_and_all_insertion_commands_c016df:
    lda f:$001D00
    .a8
    and #$80
    beq decode_dialogue_font_stream_and_all_insertion_commands_c016ea
    brl decode_dialogue_font_stream_and_all_insertion_commands_c017b0
decode_dialogue_font_stream_and_all_insertion_commands_c016ea:
    lda a:$0000,Y
    iny
    .a8
    cmp #$7F
    bne decode_dialogue_font_stream_and_all_insertion_commands_c016f5
    brl decode_dialogue_font_stream_and_all_insertion_commands_c017b0
decode_dialogue_font_stream_and_all_insertion_commands_c016f5:
    .a8
    cmp #$D3
    bcs decode_dialogue_font_stream_and_all_insertion_commands_c0170d
    .a8
    cmp #$80
    bcs decode_dialogue_font_stream_and_all_insertion_commands_c0172b
    .a8
    cmp #$5F
    bcc decode_dialogue_font_stream_and_all_insertion_commands_c01730
    phx
    rep #$20
    .a16
    and #$00FF
    sec
    .a16
    sbc #$0060
    bra decode_dialogue_font_stream_and_all_insertion_commands_c01717
decode_dialogue_font_stream_and_all_insertion_commands_c0170d:
    phx
    rep #$20
    .a16
    and #$00FF
    sec
    .a16
    sbc #$00C3
decode_dialogue_font_stream_and_all_insertion_commands_c01717:
    asl
    tax
    lda f:$C77299,X
    sta f:$7EA173
    plx
    sep #$20
    jsr routine_c017c7
    lda f:$7EA174
decode_dialogue_font_stream_and_all_insertion_commands_c0172b:
    jsr routine_c017c7
    bra decode_dialogue_font_stream_and_all_insertion_commands_c016df
decode_dialogue_font_stream_and_all_insertion_commands_c01730:
    pha
    lda f:$7EA212
    .a8
    ora #$01
    sta f:$7EA212
    pla
    sec
    .a8
    sbc #$53
    bcc decode_dialogue_font_stream_and_all_insertion_commands_c01772
    .a8
    cmp #$0A
    bcs decode_dialogue_font_stream_and_all_insertion_commands_c01772
    pha
    .a8
    cmp #$05
    bcs decode_dialogue_font_stream_and_all_insertion_commands_c01754
    lda f:$001D00
    .a8
    ora #$08
    sta f:$001D00
decode_dialogue_font_stream_and_all_insertion_commands_c01754:
    pla
    rep #$20
    pha
    txa
    sta f:$7EA173
    pla
    .a16
    and #$00FF
    asl
    tax
    jsr ($1A22,X)
    rep #$20
    lda f:$7EA173
    tax
    sep #$20
    brl decode_dialogue_font_stream_and_all_insertion_commands_c016df
decode_dialogue_font_stream_and_all_insertion_commands_c01772:
    lda f:$001D00
    .a8
    bit #$08
    beq decode_dialogue_font_stream_and_all_insertion_commands_c0179b
    .a8
    and #$F7
    sta f:$001D00
    lda f:$7EA1D3
    sta f:$001D03
    pha
    plb
    rep #$20
    lda f:$7EA1D1
    inc
    sta f:$001D01
    tay
    sep #$20
    brl decode_dialogue_font_stream_and_all_insertion_commands_c016df
decode_dialogue_font_stream_and_all_insertion_commands_c0179b:
    dey
    bra decode_dialogue_font_stream_and_all_insertion_commands_c017ba
decode_dialogue_font_stream_and_all_insertion_commands_c0179e:
    plx
    lda f:$7EA1C6
    bne decode_dialogue_font_stream_and_all_insertion_commands_c017ba
    .a8
    lda #$00
    sta f:$7EA1C5
    inc
    sta f:$7EA1C6
decode_dialogue_font_stream_and_all_insertion_commands_c017b0:
    lda f:$7EA1CE
    .a8
    ora #$80
    sta f:$7EA1CE
decode_dialogue_font_stream_and_all_insertion_commands_c017ba:
    plb
    rep #$20
    tya
    sta a:$1D01
    sep #$20
    stz a:$A1D0
    rts
    phb
    pha
    .a8
    lda #$7E
    pha
    plb
    pla
    sta a:$A1A4,X
    inx
    inc a:$A1CE
    lda a:$A1CA
    dec a:$A1CA
    plb
    dec
    bne decode_dialogue_font_stream_and_all_insertion_commands_c01803
    lda f:$001D00
    .a8
    bit #$08
    beq decode_dialogue_font_stream_and_all_insertion_commands_c0179e
    .a8
    ora #$01
    .a8
    and #$F7
    sta f:$001D00
    rep #$20
    lda f:$7EA1D1
    inc
    tay
    sep #$20
    lda f:$7EA1D3
    sta f:$001D03
    bra decode_dialogue_font_stream_and_all_insertion_commands_c0179e
decode_dialogue_font_stream_and_all_insertion_commands_c01803:
    rts
    rep #$20
    .a16
    lda #$099E
    sta f:$7EA1D5
    jsr routine_c0190a
    rts
    rep #$20
    .a16
    lda #$0864
    sta f:$7EA1D5
    jsr routine_c0190a
    rts
    rep #$20
    .a16
    lda #$0800
    sta f:$7EA1D5
    jsr routine_c0190a
    rts
    rep #$20
    lda f:$001D02
    sta f:$7EA1D2
    tya
    sta f:$7EA1D1
    lda a:$0000,Y
    pha
    sep #$20
    .a8
    lda #$7E
    pha
    plb
    rep #$20
    pla
    .a16
    and #$00FF
    asl
    asl
    sta a:$A199
    asl
    clc
    adc a:$A199
    tax
    .a16
    lda #$A22F
    sta f:$001D01
    tay
    sep #$20
    phy
    .a8
    lda #$0C
    .i16
    ldy #$0000
decode_dialogue_font_stream_and_all_insertion_commands_c01865:
    xba
    lda a:$CC00,X
    sta a:$A22F,Y
    inx
    iny
    xba
    dec
    bne decode_dialogue_font_stream_and_all_insertion_commands_c01865
    sta a:$A22F,Y
    ply
    rts
    rts
    sep #$20
    .a8
    lda #$00
    sta f:$7EA1D4
    rep #$20
    rts
    lda a:$0000,Y
    iny
    .a16
    and #$00FF
    sta f:$7EA1CE
    sta f:$7EA173
    rts
    sep #$20
    lda a:$0000,Y
    iny
    jsr routine_c018fb
    rts
    sep #$20
    lda a:$0000,Y
    iny
    pha
    jsr routine_c018fb
    .a8
    lda #$00
    xba
    lda f:$7EA1D4
    tax
    inc
    sta f:$7EA1D4
    pla
    sta f:$7EA1D7,X
    rts
    tya
    sta f:$7EA1D5
    lda f:$001D00
    .a16
    ora #$0080
    sta f:$001D00
    phx
    phy
    lda f:$7EA1D4
    .a16
    and #$00FF
    tay
    lda f:$7EA1CE
    .a16
    and #$00FF
    pha
    dec
    tax
    lda f:$7EA1A4,X
    .a16
    and #$00FF
    .a16
    cmp #$00CC
    beq decode_dialogue_font_stream_and_all_insertion_commands_c018ed
    pla
    bra decode_dialogue_font_stream_and_all_insertion_commands_c018ef
decode_dialogue_font_stream_and_all_insertion_commands_c018ed:
    pla
    dec
decode_dialogue_font_stream_and_all_insertion_commands_c018ef:
    sep #$20
    tyx
    sta f:$7EA1D7,X
    rep #$20
    ply
    plx
    rts
    phb
    pha
    .a8
    lda #$7E
    pha
    plb
    pla
    sta a:$A1CE
    sta a:$A173
    plb
    rts
    rep #$20
    lda f:$001D02
    sta f:$7EA1D2
    tya
    sta f:$7EA1D1
    lda a:$0000,Y
    .a16
    and #$00FF
    asl
    clc
    adc f:$7EA1D5
    tax
    lda f:$CA0000,X
    sta f:$001D01
    tay
    sep #$20
    .a8
    lda #$CA
    pha
    plb
    rts
