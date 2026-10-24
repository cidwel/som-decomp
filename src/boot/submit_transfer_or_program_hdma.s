; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

boot_c365 = $C365

.segment "CODE"
.org $90DA
submit_transfer_or_program_hdma:
    phd
    php
    rep #$30
    phx
    tsc
    tcd
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    .i16
    cpx #$0000
    bne submit_transfer_or_program_hdma_90f0
    jmp submit_transfer_or_program_hdma_915e
submit_transfer_or_program_hdma_90f0:
    stx $01
    lda a:$000F,X
    .a8
    cmp #$05
    beq submit_transfer_or_program_hdma_9118
    .a8
    ora #$80
    sta a:$000F,X
    php
    sei
    rep #$20
    lda a:$006C
    asl
    clc
    adc a:$0066
    tax
    lda $01
    sta a:$0000,X
    sep #$20
    inc a:$006C
    plp
    bra submit_transfer_or_program_hdma_915e
submit_transfer_or_program_hdma_9118:
    lda a:$0009,X
    rep #$20
    .a16
    and #$00FF
    tax
    jsr boot_c365
    asl
    asl
    asl
    asl
    tax
    ldy $01
    lda a:$0000,Y
    sta f:$004300,X
    lda a:$0001,Y
    sta f:$004301,X
    lda a:$0004,Y
    sta f:$004304,X
    rep #$20
    lda a:$0002,Y
    sta f:$004302,X
    sep #$20
    lda a:$0009,Y
    ora a:$0070
    sta a:$0070
    lda a:$0009,Y
    .a8
    cmp #$01
    bne submit_transfer_or_program_hdma_915e
    sty a:$007A
submit_transfer_or_program_hdma_915e:
    plb
    pla
    pla
    plp
    pld
    rts
