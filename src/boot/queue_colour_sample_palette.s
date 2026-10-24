; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_and_fill_bytes = $B0A1
allocate_transfer_descriptor = $8FC7
pack_five_bit_colour_components = $8411
submit_transfer_or_program_hdma = $90DA

.segment "CODE"
.org $8686
queue_colour_sample_palette:
    phd
    php
    rep #$30
    tsc
    sec
    .a16
    sbc #$0006
    tcd
    tcs
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    rep #$20
    .a16
    lda #$0000
    .i16
    ldx #$0200
    jsr allocate_and_fill_bytes
    stx a:$001C
    txy
    .a16
    lda #$00E8
    sta $01
    ldx a:$001A
queue_colour_sample_palette_86af:
    phx
    phy
    jsr pack_five_bit_colour_components
    ply
    sta a:$0000,Y
    iny
    iny
    pla
    clc
    .a16
    adc #$0004
    tax
    dec $01
    bne queue_colour_sample_palette_86af
    .a16
    lda #$000A
    jsr allocate_transfer_descriptor
    lda a:$001C
    sta a:$0002,X
    .a16
    lda #$01D0
    sta a:$0005,X
    sep #$20
    .a8
    lda #$0F
    sta a:$000A,X
    .a8
    lda #$7F
    sta a:$0004,X
    jsr submit_transfer_or_program_hdma
    plb
    rep #$20
    tsc
    clc
    .a16
    adc #$0006
    tcs
    plp
    pld
    rts
