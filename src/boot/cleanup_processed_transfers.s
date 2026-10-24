; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

boot_b0d6 = $B0D6
boot_c3bf = $C3BF
release_transfer_descriptor = $9066

.segment "CODE"
.org $92E9
cleanup_processed_transfers:
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
    lda a:$006E
    beq cleanup_processed_transfers_9347
    sta $01
    ldy a:$0066
cleanup_processed_transfers_9303:
    phy
    ldx a:$0000,Y
    lda a:$000F,X
    .a16
    and #$0008
    beq cleanup_processed_transfers_931b
    ldy a:$0002,X
    tyx
    jsr boot_b0d6
    ply
    phy
    ldx a:$0000,Y
cleanup_processed_transfers_931b:
    jsr release_transfer_descriptor
    ply
    iny
    iny
    dec $01
    bne cleanup_processed_transfers_9303
    lda a:$006E
    asl
    rep #$20
    .a16
    and #$00FF
    clc
    adc a:$0066
    tax
    lda a:$006C
    sec
    sbc a:$006E
    sta a:$006C
    asl
    ldy a:$0066
    jsr boot_c3bf
    stz a:$006E
cleanup_processed_transfers_9347:
    plb
    sep #$20
    pla
    pla
    plp
    pld
    rts
