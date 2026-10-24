; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-descriptor-reference-reservation.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $8F65
reserve_native_first_dma_descriptor_reference:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    ldx a:$0068
    .i16
    ldy #$0020
reserve_native_first_dma_descriptor_reference_8f76:
    lda a:$0000,X
    beq reserve_native_first_dma_descriptor_reference_8f7e
    dey
    bne reserve_native_first_dma_descriptor_reference_8f76
reserve_native_first_dma_descriptor_reference_8f7e:
    tya
    beq reserve_native_first_dma_descriptor_reference_8f84
    inc a:$0000,X
reserve_native_first_dma_descriptor_reference_8f84:
    sec
    .a8
    sbc #$20
    .a8
    eor #$FF
    inc
    inc
    plb
    plp
    pld
    rts
