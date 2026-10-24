; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $D5F3
allocate_vram_pages:
    phd
    php
    rep #$30
    pha
    tsc
    sec
    .a16
    sbc #$0006
    tcd
    tcs
    lda $07,S
    sep #$20
    phb
    pha
    .a8
    lda #$7F
    pha
    plb
    pla
    sta $02
    xba
    sta $04
    lsr
    lsr
    lsr
    lsr
    sta $05
    stz $06
    .a8
    lda #$20
    sta $01
    lda $05
    ldx a:$032C
allocate_vram_pages_d620:
    lsr
    bcs allocate_vram_pages_d627
    lsr $01
    bra allocate_vram_pages_d620
allocate_vram_pages_d627:
    lda a:$0000,X
    bne allocate_vram_pages_d63e
    stx $07
    lda $02
    sta $03
allocate_vram_pages_d632:
    dec $03
    beq allocate_vram_pages_d64f
    inx
    lda a:$0000,X
    beq allocate_vram_pages_d632
    ldx $07
allocate_vram_pages_d63e:
    clc
    rep #$20
    txa
    adc $05
    tax
    sep #$20
    dec $01
    bne allocate_vram_pages_d627
    .a8
    lda #$FF
    bra allocate_vram_pages_d669
allocate_vram_pages_d64f:
    lda $02
    sta $01
    ldx $07
    lda $04
allocate_vram_pages_d657:
    sta a:$0000,X
    inx
    dec $01
    bne allocate_vram_pages_d657
    rep #$20
    lda $07
    sec
    sbc a:$032C
    sep #$20
allocate_vram_pages_d669:
    plb
    rep #$20
    sta $07,S
    tsc
    clc
    .a16
    adc #$0006
    tcs
    pla
    plp
    pld
    rts
