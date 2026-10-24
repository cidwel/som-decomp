; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-dma-descriptor-pass.md.
.setcpu "65816"
.smart
.a8
.i16

submit_transfer_or_program_hdma = $90DA

.segment "CODE"
.org $91B8
program_dma_descriptor_pass:
    phd
    php
    rep #$30
    sep #$20
    phb
    pha
    .a8
    lda #$7F
    pha
    plb
    pla
    rep #$20
    pha
    lda a:$006E
    bne program_dma_descriptor_pass_91d0
    jmp program_dma_descriptor_pass_92e4
program_dma_descriptor_pass_91d0:
    sep #$20
    .a8
    lda #$00
    sta f:$00420C
    rep #$20
    .a16
    lda #$0106
    sec
    sbc $01,S
    sta $01,S
    phd
    .a16
    lda #$4300
    tcd
    lda a:$006E
    ldy a:$0066
program_dma_descriptor_pass_91ed:
    pha
    phy
    ldx a:$0000,Y
    sep #$20
    lda f:$002137
    lda f:$00213D
    xba
    lda f:$00213D
    lsr
    xba
    ror
    xba
    ror
    .a8
    and #$80
    rep #$20
    clc
    adc a:$0005,X
    lsr
    lsr
    lsr
    lsr
    lsr
    lsr
    lsr
    cmp $07,S
    bcc program_dma_descriptor_pass_921d
    ply
    jmp program_dma_descriptor_pass_92c4
program_dma_descriptor_pass_921d:
    phx
    sep #$20
    .a8
    lda #$00
    sta f:$00420B
    lda a:$0000,X
    sta $00
    rep #$20
    lda a:$0001,X
    sta $01
    lda a:$0003,X
    sta $03
    lda a:$0005,X
    sta $05
    plx
    .a16
    lda #$2100
    tcd
    sep #$20
    lda a:$0009,X
    sta $15
    lda a:$000F,X
    .a8
    and #$07
    dec
    beq program_dma_descriptor_pass_9279
    dec
    beq program_dma_descriptor_pass_9272
    dec
    beq program_dma_descriptor_pass_9261
    rep #$20
    lda a:$000A,X
    sta $02
    sep #$20
    bra program_dma_descriptor_pass_9282
program_dma_descriptor_pass_9261:
    lda a:$000A,X
    sta $81
    lda a:$000B,X
    sta $82
    lda a:$000C,X
    sta $83
    bra program_dma_descriptor_pass_9282
program_dma_descriptor_pass_9272:
    lda a:$000A,X
    sta $21
    bra program_dma_descriptor_pass_9282
program_dma_descriptor_pass_9279:
    rep #$20
    lda a:$000A,X
    sta $16
    sep #$20
program_dma_descriptor_pass_9282:
    .a8
    lda #$01
    sta f:$00420B
    nop
    nop
    nop
    nop
    rep #$20
    ply
    iny
    iny
    .a16
    lda #$4300
    tcd
    lda f:$004212
    .a16
    bit #$0080
    beq program_dma_descriptor_pass_92c4
    lda $05
    bne program_dma_descriptor_pass_92c4
    pla
    dec
    beq program_dma_descriptor_pass_92a9
    jmp program_dma_descriptor_pass_91ed
program_dma_descriptor_pass_92a9:
    pld
    sep #$20
    lda f:$004212
    .a8
    bit #$80
    bne program_dma_descriptor_pass_92d5
    lda a:$0010
    bne program_dma_descriptor_pass_92d5
    dec a:$006E
    .a8
    lda #$00
    sta f:$00420B
    bra program_dma_descriptor_pass_92d5
program_dma_descriptor_pass_92c4:
    stz $05
    pla
    sec
    sbc a:$006E
    .a16
    eor #$FFFF
    inc
    sta a:$006E
    pld
    sep #$20
program_dma_descriptor_pass_92d5:
    ldx a:$007A
    beq program_dma_descriptor_pass_92dd
    jsr submit_transfer_or_program_hdma
program_dma_descriptor_pass_92dd:
    lda a:$0070
    sta f:$00420C
program_dma_descriptor_pass_92e4:
    plx
    plb
    plp
    pld
    rts
