; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_transfer_descriptor = $8FC7
find_registered_vram_buffer = $C73B
submit_transfer_or_program_hdma = $90DA

.segment "CODE"
.org $C870
queue_registered_vram_buffer:
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
    stx $03
    jsr find_registered_vram_buffer
    lda a:$0000,X
    .a16
    and #$00FF
    xba
    asl
    asl
    sta $01
    lda a:$0001,X
    .a16
    and #$00FF
    xba
    sta $05
    .a16
    lda #$0001
    jsr allocate_transfer_descriptor
    lda $01
    sta a:$000A,X
    lda $03
    sta a:$0002,X
    lda $05
    sta a:$0005,X
    sep #$20
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
