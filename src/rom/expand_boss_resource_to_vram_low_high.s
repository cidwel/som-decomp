; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $255E
expand_boss_resource_to_vram_low_high:
    sep #$10
    phb
    .i8
    ldx #$00
    phx
    plb
    stz $70
    clc
    lda $68
    .a16
    adc #$0007
    lsr
    lsr
    lsr
    sta $68
expand_boss_resource_to_vram_low_high_c22572:
    lda [$79]
    xba
    sta $6E
    inc $79
    .i8
    ldx #$08
expand_boss_resource_to_vram_low_high_c2257b:
    asl $6E
    bcc expand_boss_resource_to_vram_low_high_c22585
    lda [$79]
    inc $79
    bra expand_boss_resource_to_vram_low_high_c22587
expand_boss_resource_to_vram_low_high_c22585:
    lda $6C
expand_boss_resource_to_vram_low_high_c22587:
    ldy $6A
    sty $6C
    sta $6A
    lda $70
    .a16
    eor #$0001
    sta $70
    beq expand_boss_resource_to_vram_low_high_c2259d
    ldy $6A
    sty a:$2118
    bra expand_boss_resource_to_vram_low_high_c225a2
expand_boss_resource_to_vram_low_high_c2259d:
    ldy $6A
    sty a:$2119
expand_boss_resource_to_vram_low_high_c225a2:
    dex
    bne expand_boss_resource_to_vram_low_high_c2257b
    dec $68
    bne expand_boss_resource_to_vram_low_high_c22572
    plb
    rep #$10
    rts
