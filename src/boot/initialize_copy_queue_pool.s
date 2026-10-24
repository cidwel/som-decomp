; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

boot_b081 = $B081

.segment "CODE"
.org $C8C8
initialize_copy_queue_pool:
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
    rep #$20
    .i16
    ldx #$0100
    jsr boot_b081
    stx a:$02F6
    txa
    clc
    .a16
    adc #$0008
    sta a:$02F8
    tax
    .i16
    ldy #$001E
initialize_copy_queue_pool_c8ed:
    clc
    .a16
    adc #$0008
    sta a:$0000,X
    tax
    dey
    bne initialize_copy_queue_pool_c8ed
    stz a:$0000,X
    stz a:$02FE
    .a16
    lda #$02FE
    sta a:$0300
    stz a:$02FA
    .a16
    lda #$02FA
    sta a:$02FC
    plb
    sep #$20
    pla
    pla
    plp
    pld
    rts
