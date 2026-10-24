; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $BBAB
allocate_palette_slot:
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
    .a16
    and #$000F
    asl
    asl
    asl
    asl
    asl
    clc
    adc a:$02D2
    tax
    .i16
    ldy #$0008
allocate_palette_slot_bbca:
    .a16
    lda #$8000
    bit a:$0000,X
    bne allocate_palette_slot_bbe0
    clc
    txa
    .a16
    adc #$0020
    tax
    dey
    bne allocate_palette_slot_bbca
    .i16
    ldx #$0000
    bra allocate_palette_slot_bbe3
allocate_palette_slot_bbe0:
    stz a:$0000,X
allocate_palette_slot_bbe3:
    plb
    plp
    pld
    rts
