; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

expand_boss_loader_resource_to_bus = $24F1

.segment "CODE"
.org $24C3
prepare_boss_loader_resource_expansion:
    asl
    asl
    asl
    tax
    sep #$20
    lda f:$D0BC52,X
    sta $7B
    lda f:$D0BC53,X
    sta $7E
    rep #$20
    lda f:$D0BC54,X
    sta $79
    lda f:$D0BC56,X
    sta $7C
    lda f:$D0BC58,X
    sta $68
    stz $6A
    stz $6C
    jsr expand_boss_loader_resource_to_bus
    rts
