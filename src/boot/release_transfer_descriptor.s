; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

boot_c365 = $C365

.segment "CODE"
.org $9066
release_transfer_descriptor:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    .i16
    cpx #$0000
    beq release_transfer_descriptor_90d6
    lda a:$000D,X
    beq release_transfer_descriptor_909d
    .a8
    cmp #$20
    beq release_transfer_descriptor_9081
    bcs release_transfer_descriptor_909d
release_transfer_descriptor_9081:
    dec
    rep #$20
    .a16
    and #$00FF
    clc
    adc a:$0068
    tay
    sep #$20
    lda a:$0000,Y
    dec
    .a8
    cmp #$01
    beq release_transfer_descriptor_9098
    bcs release_transfer_descriptor_909a
release_transfer_descriptor_9098:
    .a8
    lda #$00
release_transfer_descriptor_909a:
    sta a:$0000,Y
release_transfer_descriptor_909d:
    lda a:$000F,X
    .a8
    cmp #$05
    bne release_transfer_descriptor_90d3
    lda a:$0009,X
    .a8
    eor #$FF
    and a:$0070
    sta a:$0070
    lda a:$0009,X
    phx
    rep #$20
    .a16
    and #$00FF
    tax
    jsr boot_c365
    .a16
    and #$0007
    tax
    sep #$20
    stz a:$0072,X
    plx
    lda a:$0009,X
    .a8
    cmp #$01
    bne release_transfer_descriptor_90d3
    stz a:$007A
    stz a:$007B
release_transfer_descriptor_90d3:
    stz a:$000F,X
release_transfer_descriptor_90d6:
    plb
    plp
    pld
    rts
