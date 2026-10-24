; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

current_task_id = $ACE9

.segment "CODE"
.org $AF59
allocate_128_byte_units:
    phd
    php
    rep #$30
    pha
    tsc
    sec
    .a16
    sbc #$0005
    tcd
    tcs
    lda $06,S
    sep #$20
    phb
    pha
    .a8
    lda #$7F
    pha
    plb
    pla
    sta $02
    stz $03
    jsr current_task_id
    sta $07
    ldx a:$00C2
    stx $04
    .a8
    lda #$00
    sec
    sbc a:$00C2
    sta $01
    lda $02
    sta $06
allocate_128_byte_units_af8a:
    lda a:$00C4,X
    bne allocate_128_byte_units_af95
    dec $06
    beq allocate_128_byte_units_afa5
    bra allocate_128_byte_units_af9b
allocate_128_byte_units_af95:
    lda $02
    sta $06
    stx $04
allocate_128_byte_units_af9b:
    inx
    dec $01
    bne allocate_128_byte_units_af8a
    .i16
    ldx #$0000
    bra allocate_128_byte_units_b003
allocate_128_byte_units_afa5:
    .a8
    lda #$00
    sec
    sbc $01
    cmp a:$00C0
    beq allocate_128_byte_units_afb4
    bcc allocate_128_byte_units_afb4
    sta a:$00C0
allocate_128_byte_units_afb4:
    rep #$20
    lda $04
    cmp a:$00C2
    bne allocate_128_byte_units_afd8
    clc
    adc $02
    tay
    sep #$20
allocate_128_byte_units_afc3:
    lda a:$00C4,Y
    beq allocate_128_byte_units_afd0
    iny
    dec $01
    bne allocate_128_byte_units_afc3
    .i16
    ldy #$0000
allocate_128_byte_units_afd0:
    sty a:$00C2
    rep #$20
    lda $04
    dec
allocate_128_byte_units_afd8:
    inc
    tax
    sta $04
    sep #$20
    lda $02
    sta $01
allocate_128_byte_units_afe2:
    lda $01
    sta a:$00C4,X
    lda $07
    sta a:$01C4,X
    inx
    dec $01
    bne allocate_128_byte_units_afe2
    rep #$20
    lda $04
    asl
    asl
    asl
    asl
    asl
    asl
    asl
    clc
    .a16
    adc #$0000
    tax
    sep #$20
allocate_128_byte_units_b003:
    plb
    rep #$20
    tsc
    clc
    .a16
    adc #$0007
    tcs
    plp
    pld
    rts
