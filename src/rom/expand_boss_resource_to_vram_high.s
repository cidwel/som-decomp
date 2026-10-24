; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $25D7
expand_boss_resource_to_vram_high:
    sep #$10
    phb
    .i8
    ldx #$00
    phx
    plb
    clc
    lda $68
    .a16
    adc #$0007
    lsr
    lsr
    lsr
    sta $68
expand_boss_resource_to_vram_high_c225e9:
    lda [$79]
    xba
    sta $6E
    inc $79
    .i8
    ldx #$08
expand_boss_resource_to_vram_high_c225f2:
    asl $6E
    bcc expand_boss_resource_to_vram_high_c225fc
    lda [$79]
    inc $79
    bra expand_boss_resource_to_vram_high_c225fe
expand_boss_resource_to_vram_high_c225fc:
    lda $6C
expand_boss_resource_to_vram_high_c225fe:
    ldy $6A
    sty $6C
    sta $6A
    ldy $6A
    sty a:$2119
    dex
    bne expand_boss_resource_to_vram_high_c225f2
    dec $68
    bne expand_boss_resource_to_vram_high_c225e9
    plb
    rep #$10
    rts
