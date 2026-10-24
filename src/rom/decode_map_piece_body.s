; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $CD93
decode_map_piece_body:
    sep #$30
    .a8
    lda #$00
    sta $04
decode_map_piece_body_c0cd99:
    ldy $04
decode_map_piece_body_c0cd9b:
    lda [$1D]
    inc $1D
    bne decode_map_piece_body_c0cda7
    inc $1E
    bne decode_map_piece_body_c0cda7
    inc $1F
decode_map_piece_body_c0cda7:
    ldy $04
    .a8
    cmp #$C0
    bcs decode_map_piece_body_c0cdcc
    sta ($12),Y
decode_map_piece_body_c0cdaf:
    iny
    sty $04
    cpy $14
    bcc decode_map_piece_body_c0cd9b
    tya
    sbc $14
    sta $04
    rep #$20
    lda $12
    clc
    .a16
    adc #$0080
    sta $12
    sep #$20
    dec $15
    bne decode_map_piece_body_c0cd99
    rts
decode_map_piece_body_c0cdcc:
    .a8
    cmp #$E0
    bcs decode_map_piece_body_c0cde0
    pha
    .a8
    and #$07
    tax
    pla
    lsr
    lsr
    lsr
    .a8
    and #$03
    inc
    sta $02
    jmp decode_map_piece_body_c0cff1
decode_map_piece_body_c0cde0:
    bne decode_map_piece_body_c0ce0c
    lda [$1D]
    inc $1D
    bne decode_map_piece_body_c0cdee
    inc $1E
    bne decode_map_piece_body_c0cdee
    inc $1F
decode_map_piece_body_c0cdee:
    ldy $04
    pha
    .a8
    and #$80
    sta $00
    stz $01
    pla
    .a8
    and #$7F
    tax
    rep #$20
    lda $12
    sec
    sbc $00
    .a16
    sbc #$0080
    sta $00
    sep #$20
    jmp decode_map_piece_body_c0cf05
decode_map_piece_body_c0ce0c:
    .a8
    cmp #$E8
    bcs decode_map_piece_body_c0ce22
    .a8
    and #$07
    tax
    rep #$20
    lda $12
    sec
    .a16
    sbc #$0080
    sta $00
    sep #$20
    jmp decode_map_piece_body_c0cf05
decode_map_piece_body_c0ce22:
    .a8
    cmp #$F0
    bcs decode_map_piece_body_c0ce4c
    .a8
    and #$07
    sta $02
    lda [$1D]
    inc $1D
    bne decode_map_piece_body_c0ce36
    inc $1E
    bne decode_map_piece_body_c0ce36
    inc $1F
decode_map_piece_body_c0ce36:
    ldy $04
    .a8
    cmp #$80
    rol $02
    inc $02
    .a8
    and #$7F
    tax
    lda $12
    sta $00
    lda $13
    sta $01
    jmp decode_map_piece_body_c0cf94
decode_map_piece_body_c0ce4c:
    bne decode_map_piece_body_c0ce63
    lda [$1D]
    inc $1D
    bne decode_map_piece_body_c0ce5a
    inc $1E
    bne decode_map_piece_body_c0ce5a
    inc $1F
decode_map_piece_body_c0ce5a:
    ldy $04
    .a8
    cmp #$80
    php
    .a8
    and #$7F
    bra decode_map_piece_body_c0ce93
decode_map_piece_body_c0ce63:
    .a8
    cmp #$F8
    bcs decode_map_piece_body_c0ce6d
    .a8
    and #$07
    clc
    php
    bra decode_map_piece_body_c0ce93
decode_map_piece_body_c0ce6d:
    .a8
    and #$07
    pha
    asl
    asl
    tax
    lda a:$FF00,X
    lda $16
    inc $16
    asl
    asl
    tax
    lda $12
    clc
    adc $04
    sta a:$FF22,X
    lda $13
    sta a:$FF23,X
    pla
    .a8
    ora #$80
    sta a:$FF20,X
    jmp decode_map_piece_body_c0cdaf
decode_map_piece_body_c0ce93:
    tax
    dey
    lda ($12),Y
    .i8
    cpy #$80
    bcc decode_map_piece_body_c0ceae
    tya
    clc
    adc $14
    tay
    rep #$20
    lda $12
    sec
    .a16
    sbc #$0080
    sta $00
    sep #$20
    lda ($00),Y
decode_map_piece_body_c0ceae:
    ldy $04
    plp
    bcs decode_map_piece_body_c0cedc
decode_map_piece_body_c0ceb3:
    inc
    sta ($12),Y
    iny
    cpy $14
    bcc decode_map_piece_body_c0ced4
    pha
    tya
    sbc $14
    tay
    sta $04
    rep #$20
    lda $12
    clc
    .a16
    adc #$0080
    sta $12
    sep #$20
    pla
    dec $15
    bne decode_map_piece_body_c0ced4
    rts
decode_map_piece_body_c0ced4:
    dex
    bpl decode_map_piece_body_c0ceb3
    sty $04
    jmp decode_map_piece_body_c0cd9b
decode_map_piece_body_c0cedc:
    dec
    sta ($12),Y
    iny
    cpy $14
    bcc decode_map_piece_body_c0cefd
    pha
    tya
    sbc $14
    tay
    sta $04
    rep #$20
    lda $12
    clc
    .a16
    adc #$0080
    sta $12
    sep #$20
    pla
    dec $15
    bne decode_map_piece_body_c0cefd
    rts
decode_map_piece_body_c0cefd:
    dex
    bpl decode_map_piece_body_c0cedc
    sty $04
    jmp decode_map_piece_body_c0cd9b
decode_map_piece_body_c0cf05:
    txa
    stx $02
    sec
    adc $04
    cmp $14
    bcs decode_map_piece_body_c0cf2c
    sta $04
    rep #$30
    tya
    clc
    adc $00
    tax
    tya
    clc
    adc $12
    tay
    lda $02
    .a16
    and #$007F
    mvn #$7F, #$7F
    sep #$30
    ldy $04
    jmp decode_map_piece_body_c0cd9b
decode_map_piece_body_c0cf2c:
    sbc $14
    sta $04
    .a8
    eor #$FF
    inc
    clc
    adc $02
    sta $02
    rep #$30
    tya
    clc
    adc $00
    tax
    tya
    clc
    adc $12
    tay
    lda $02
    .a16
    and #$007F
decode_map_piece_body_c0cf49:
    mvn #$7F, #$7F
    lda $00
    clc
    .a16
    adc #$0080
    sta $00
    lda $12
    clc
    .a16
    adc #$0080
    sta $12
    sep #$30
    dec $15
    bne decode_map_piece_body_c0cf63
    rts
decode_map_piece_body_c0cf63:
    ldy $04
    beq decode_map_piece_body_c0cf91
    tya
    cmp $14
    bcc decode_map_piece_body_c0cf7e
    sbc $14
    sta $04
    rep #$30
    ldx $00
    ldy $12
    lda $14
    .a16
    and #$007F
    dec
    bra decode_map_piece_body_c0cf49
decode_map_piece_body_c0cf7e:
    rep #$30
    ldx $00
    ldy $12
    lda $04
    .a16
    and #$007F
    dec
    mvn #$7F, #$7F
    sep #$30
    ldy $04
decode_map_piece_body_c0cf91:
    jmp decode_map_piece_body_c0cd9b
decode_map_piece_body_c0cf94:
    lda $04
    sec
    sbc $02
    sta $02
    bcs decode_map_piece_body_c0cfad
    adc $14
    sta $02
    rep #$20
    lda $00
    sec
    .a16
    sbc #$0080
    sta $00
    sep #$20
decode_map_piece_body_c0cfad:
    ldy $02
    lda ($00),Y
    ldy $04
    sta ($12),Y
    inc $02
    lda $02
    cmp $14
    bcc decode_map_piece_body_c0cfcd
    sbc $14
    sta $02
    rep #$20
    lda $00
    clc
    .a16
    adc #$0080
    sta $00
    sep #$20
decode_map_piece_body_c0cfcd:
    iny
    sty $04
    cpy $14
    bcc decode_map_piece_body_c0cfeb
    tya
    sbc $14
    tay
    sta $04
    rep #$20
    lda $12
    clc
    .a16
    adc #$0080
    sta $12
    sep #$20
    dec $15
    bne decode_map_piece_body_c0cfeb
    rts
decode_map_piece_body_c0cfeb:
    dex
    bpl decode_map_piece_body_c0cfad
    jmp decode_map_piece_body_c0cd9b
decode_map_piece_body_c0cff1:
    lda $04
    sec
    sbc $02
    tay
    lda ($12),Y
    bcs decode_map_piece_body_c0d00d
    tya
    adc $14
    tay
    rep #$20
    lda $12
    sec
    .a16
    sbc #$0080
    sta $00
    sep #$20
    lda ($00),Y
decode_map_piece_body_c0d00d:
    sta $02
    ldy $04
decode_map_piece_body_c0d011:
    sta ($12),Y
    iny
    cpy $14
    bcc decode_map_piece_body_c0d02f
    tya
    sbc $14
    tay
    rep #$20
    lda $12
    clc
    .a16
    adc #$0080
    sta $12
    sep #$20
    dec $15
    bne decode_map_piece_body_c0d02d
    rts
decode_map_piece_body_c0d02d:
    lda $02
decode_map_piece_body_c0d02f:
    dex
    bpl decode_map_piece_body_c0d011
    sty $04
    jmp decode_map_piece_body_c0cd9b
