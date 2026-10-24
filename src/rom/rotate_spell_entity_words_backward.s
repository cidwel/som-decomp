; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-resource-state.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $433E
rotate_spell_entity_words_backward:
    phd
    php
    rep #$30
    pha
    tsc
    sec
    .a16
    sbc #$0004
    tcd
    tcs
    lda $05,S
    sep #$20
    phb
    pha
    .a8
    lda #$7E
    pha
    plb
    pla
    rep #$20
    stx $01
    sta $05
    .a16
    and #$00FF
    sta $03
    lda $05
    xba
    .a16
    and #$00FF
    sta $05
    sec
    sbc $03
    beq rotate_spell_entity_words_backward_c1438e
    bcc rotate_spell_entity_words_backward_c1438e
    sta $03
    asl $05
    clc
    txa
    adc $05
    tax
    lda a:$0000,X
    sta $05
rotate_spell_entity_words_backward_c1437d:
    dex
    dex
    lda a:$0000,X
    sta a:$0002,X
    dec $03
    bne rotate_spell_entity_words_backward_c1437d
    lda $05
    sta a:$0000,X
rotate_spell_entity_words_backward_c1438e:
    plb
    tsc
    clc
    .a16
    adc #$0006
    tcs
    plp
    pld
    rts
