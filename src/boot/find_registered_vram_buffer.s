; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C73B
find_registered_vram_buffer:
    phd
    php
    rep #$30
    tsc
    sec
    .a16
    sbc #$0004
    tcd
    tcs
    .a16
    lda #$0004
    sta $01
    stx $03
    ldx a:$02F4
find_registered_vram_buffer_c750:
    lda a:$0002,X
    cmp $03
    beq find_registered_vram_buffer_c764
    clc
    txa
    .a16
    adc #$0008
    tax
    dec $01
    bne find_registered_vram_buffer_c750
    .i16
    ldx #$0000
find_registered_vram_buffer_c764:
    sep #$20
    pla
    pla
    pla
    pla
    plp
    pld
    rts
