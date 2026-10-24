; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-sprite-transfers.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $4297
copy_spell_entity_sprite_record_words:
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
    lda #$7E
    pha
    plb
    pla
    sta $01
    xba
    sta $05
    xba
    sty $03
    stx $06
    rep #$20
    .a16
    and #$00F0
    lsr
    lsr
    lsr
    clc
    adc $06
    tax
    lda $01
    .a16
    and #$000F
    inc
    sta $01
    .i16
    ldy #$0000
copy_spell_entity_sprite_record_words_c142cf:
    lda [$03],Y
    sta a:$0000,X
    iny
    iny
    inx
    inx
    dec $01
    bne copy_spell_entity_sprite_record_words_c142cf
    plb
    tsc
    clc
    .a16
    adc #$0007
    tcs
    plp
    pld
    rts
