; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_transfer_descriptor = $8FC7
boot_c34d = $C34D
read_vram_address_tag_word = $D6B3
select_graphics_registration = $805F
submit_transfer_or_program_hdma = $90DA

.segment "CODE"
.org $82D4
queue_single_graphics_block:
    phd
    php
    rep #$30
    pha
    tsc
    sec
    .a16
    sbc #$0005
    tcd
    tcs
    lda $06,S
    sep #$20
    phb
    pha
    .a8
    lda #$7F
    pha
    plb
    pla
    stx $02
    sty $04
    sta $01
    xba
    rep #$20
    .a16
    bit #$00FF
    bne queue_single_graphics_block_82fe
    .a16
    lda #$0001
    bra queue_single_graphics_block_8301
queue_single_graphics_block_82fe:
    .a16
    lda #$0009
queue_single_graphics_block_8301:
    jsr allocate_transfer_descriptor
    stx $06
    ldx $02
    jsr read_vram_address_tag_word
    jsr select_graphics_registration
    tax
    lda a:$0002,X
    jsr boot_c34d
    txa
    asl
    asl
    asl
    ldx $06
    sta a:$0005,X
    lda $02
    sta a:$000A,X
    lda $04
    sta a:$0002,X
    sep #$20
    lda $01
    sta a:$0004,X
    jsr submit_transfer_or_program_hdma
    plb
    rep #$20
    tsc
    clc
    .a16
    adc #$0007
    tcs
    plp
    pld
    rts
