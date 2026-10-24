; Recovered Secret of Mana USA routine; behaviour documented in docs/runtime-stack-copy.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $479D
copy_stack_argument_long_pointer_bytes:
    phd
    php
    rep #$20
    tsc
    sec
    .a16
    sbc #$0006
    tcd
    tcs
    sep #$20
    phb
    .a8
    lda #$00
    pha
    plb
    rep #$20
    ldx $12
    beq copy_stack_argument_long_pointer_bytes_c147e2
    lda $0C
    sta $01
    lda $0E
    sta $03
    lda $10
    sta $05
    .i16
    ldy #$0000
    txa
    .a16
    bit #$0001
    beq copy_stack_argument_long_pointer_bytes_c147d7
    sep #$20
    lda [$04],Y
    sta [$01],Y
    rep #$20
    iny
    txa
    dec
    beq copy_stack_argument_long_pointer_bytes_c147e2
copy_stack_argument_long_pointer_bytes_c147d7:
    lsr
    tax
copy_stack_argument_long_pointer_bytes_c147d9:
    lda [$04],Y
    sta [$01],Y
    iny
    iny
    dex
    bne copy_stack_argument_long_pointer_bytes_c147d9
copy_stack_argument_long_pointer_bytes_c147e2:
    plb
    tsc
    clc
    .a16
    adc #$0006
    tcs
    plp
    pld
    rts
