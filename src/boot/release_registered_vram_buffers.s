; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

boot_b0d6 = $B0D6
release_matching_vram_tag = $D678

.segment "CODE"
.org $C6CB
release_registered_vram_buffers:
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
    ldy a:$02F4
    beq release_registered_vram_buffers_c70a
    .a8
    lda #$04
    sta $01
release_registered_vram_buffers_c6e2:
    ldx a:$0002,Y
    beq release_registered_vram_buffers_c6ec
    phy
    jsr boot_b0d6
    ply
release_registered_vram_buffers_c6ec:
    lda a:$0000,Y
    beq release_registered_vram_buffers_c6f6
    phy
    jsr release_matching_vram_tag
    ply
release_registered_vram_buffers_c6f6:
    clc
    rep #$20
    tya
    .a16
    adc #$0008
    tay
    sep #$20
    dec $01
    bne release_registered_vram_buffers_c6e2
    ldx a:$02F4
    jsr boot_b0d6
release_registered_vram_buffers_c70a:
    plb
    pla
    pla
    plp
    pld
    rts
