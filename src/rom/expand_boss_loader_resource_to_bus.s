; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $24F1
expand_boss_loader_resource_to_bus:
    sep #$10
    clc
    lda $68
    .a16
    adc #$0007
    lsr
    lsr
    lsr
    sta $68
expand_boss_loader_resource_to_bus_c224fe:
    lda [$79]
    xba
    sta $6E
    inc $79
    .i8
    ldx #$08
expand_boss_loader_resource_to_bus_c22507:
    asl $6E
    bcc expand_boss_loader_resource_to_bus_c22511
    lda [$79]
    inc $79
    bra expand_boss_loader_resource_to_bus_c22513
expand_boss_loader_resource_to_bus_c22511:
    lda $6C
expand_boss_loader_resource_to_bus_c22513:
    ldy $6A
    sty $6C
    sta $6A
    sta [$7C]
    inc $7C
    dex
    bne expand_boss_loader_resource_to_bus_c22507
    lda $7C
    .a16
    cmp #$4000
    bne expand_boss_loader_resource_to_bus_c2252d
    clc
    .a16
    adc #$2000
    sta $7C
expand_boss_loader_resource_to_bus_c2252d:
    dec $68
    bne expand_boss_loader_resource_to_bus_c224fe
    rep #$10
    rts
