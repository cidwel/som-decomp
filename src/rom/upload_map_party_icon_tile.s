; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a16
.i16


dma7_source_address = $4372
dma7_mode_and_port = $4370
dma7_byte_count = $4375
dma7_source_bank = $4374
dma_enable = $420B

.segment "CODE"
.org $E723
upload_map_party_icon_tile:
    pha
    .a16
    and #$07FF
    asl
    asl
    asl
    asl
    asl
    sta a:dma7_source_address
    .a16
    lda #$1801
    sta a:dma7_mode_and_port
    .a16
    lda #$0020
    sta a:dma7_byte_count
    pla
    sep #$20
    xba
    lsr
    lsr
    lsr
    lsr
    .a8
    and #$07
    clc
    .a8
    adc #$D5
    sta a:dma7_source_bank
    .a8
    lda #$80
    sta a:dma_enable
    rep #$20
    rts
