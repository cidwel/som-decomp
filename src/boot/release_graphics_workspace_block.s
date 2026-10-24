; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

read_vram_address_tag_word = $D6B3
select_graphics_registration = $805F

.segment "CODE"
.org $8277
release_graphics_workspace_block:
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
    jsr read_vram_address_tag_word
    jsr select_graphics_registration
    sta $01
    tax
    lda a:$0002,X
    .a16
    and #$0003
    sta $05
    lda a:$0000,X
    .a16
    and #$00FF
    xba
    asl
    asl
    sec
    sbc $03
    .a16
    eor #$FFFF
    inc
    lsr
    lsr
    lsr
    dec $05
    beq release_graphics_workspace_block_82bb
    lsr
    dec $05
    beq release_graphics_workspace_block_82bb
    lsr
release_graphics_workspace_block_82bb:
    clc
    adc a:$0006,X
    sta a:$0004,X
    tax
    sep #$20
    stz a:$0000,X
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
