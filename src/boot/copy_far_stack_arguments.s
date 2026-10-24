; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C44E
copy_far_stack_arguments:
    phd
    php
    rep #$30
    tsc
    sec
    .a16
    sbc #$0004
    tcd
    tcs
    sep #$20
    phb
    .a8
    lda #$00
    pha
    plb
    rep #$20
    lda $10
    beq copy_far_stack_arguments_c4d2
    .a16
    cmp #$0011
    bcc copy_far_stack_arguments_c4b3
    dec
    sta $10
    sep #$20
    .a8
    lda #$54
    sta $01
    lda $0C
    sta $02
    lda $0F
    sta $03
    .a8
    lda #$6B
    sta $04
    ldy $0A
    ldx $0D
    inc $11
copy_far_stack_arguments_c486:
    php
    .a8
    lda #$7E
    pha
    rep #$20
    .a16
    lda #$C4A5
    pha
    sep #$20
    .a8
    lda #$00
    pha
    rep #$20
    tdc
    clc
    .a16
    adc #$0000
    pha
    sep #$20
    .a8
    lda #$00
    xba
    lda $10
    sei
    rtl
    xba
    plp
    xba
    sta $10
    dec $11
    bne copy_far_stack_arguments_c486
    rep #$20
    bra copy_far_stack_arguments_c4d2
copy_far_stack_arguments_c4b3:
    .i16
    ldy #$0000
    .a16
    bit #$0001
    beq copy_far_stack_arguments_c4c7
    sep #$20
    lda [$0D],Y
    sta [$0A],Y
    rep #$20
    iny
    dec
    beq copy_far_stack_arguments_c4d2
copy_far_stack_arguments_c4c7:
    lsr
    tax
copy_far_stack_arguments_c4c9:
    lda [$0D],Y
    sta [$0A],Y
    iny
    iny
    dex
    bne copy_far_stack_arguments_c4c9
copy_far_stack_arguments_c4d2:
    plb
    sep #$20
    pla
    pla
    pla
    pla
    plp
    pld
    rts
