; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_transfer_descriptor = $8FC7
submit_transfer_or_program_hdma = $90DA

.segment "CODE"
.org $BD09
queue_constant_palette_upload:
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
    stx $01
    .a16
    lda #$0002
    jsr allocate_transfer_descriptor
    .a16
    lda #$0020
    sta a:$0005,X
    .a16
    lda #$BCE9
    sta a:$0002,X
    lda $01
    sec
    sbc a:$02D2
    lsr
    sep #$20
    pha
    sta a:$000A,X
    .a8
    lda #$7E
    sta a:$0004,X
    jsr submit_transfer_or_program_hdma
    pla
    lsr
    lsr
    lsr
    lsr
    plb
    sta $02,S
    pla
    pla
    plp
    pld
    rts
