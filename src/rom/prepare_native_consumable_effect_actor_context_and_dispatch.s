; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-consumable-effects.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $54E7
prepare_native_consumable_effect_actor_context_and_dispatch:
    phd
    phb
    php
    rep #$30
    pha
    .a16
    lda #$0300
    tcd
    pla
    .a16
    and #$000F
    sta $AC
    sep #$20
    .a8
    lda #$7E
    pha
    plb
    .a8
    lda #$10
    sta a:$E1F8,X
    lda $80
    .a8
    ora #$40
    sta $80
    lda $AC
    asl
    txy
    stz a:$E1F1,X
    stz a:$E1F2,X
    stz a:$E059,X
    tax
    asl
    asl
    asl
    jmp ($551C,X)
