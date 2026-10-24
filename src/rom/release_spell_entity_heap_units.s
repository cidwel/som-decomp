; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-memory.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $3CB8
release_spell_entity_heap_units:
    phd
    php
    rep #$20
    tsc
    sec
    .a16
    sbc #$0006
    tcd
    tcs
    stx $02
    txa
    beq release_spell_entity_heap_units_c13d20
    sec
    .a16
    sbc #$8200
    .a16
    and #$003F
    bne release_spell_entity_heap_units_c13d20
    lda $02
    sec
    .a16
    sbc #$8200
    lsr
    lsr
    lsr
    lsr
    lsr
    lsr
    sep #$20
    sta $01
    rep #$20
    .a16
    and #$00FF
    tax
    sep #$20
    lda a:$823A,X
    sta $04
    beq release_spell_entity_heap_units_c13d1e
    lda a:$823A,X
    sta $06
    phx
release_spell_entity_heap_units_c13cf6:
    stz a:$823A,X
    stz a:$832A,X
    inx
    dec $06
    bne release_spell_entity_heap_units_c13cf6
    plx
    lda $04
release_spell_entity_heap_units_c13d04:
    dex
    lda a:$823A,X
    sec
    sbc $04
    beq release_spell_entity_heap_units_c13d14
    bcc release_spell_entity_heap_units_c13d14
    sta a:$823A,X
    bra release_spell_entity_heap_units_c13d04
release_spell_entity_heap_units_c13d14:
    lda $01
    cmp a:$8238
    bcs release_spell_entity_heap_units_c13d1e
    sta a:$8238
release_spell_entity_heap_units_c13d1e:
    rep #$20
release_spell_entity_heap_units_c13d20:
    tsc
    clc
    .a16
    adc #$0006
    tcs
    plp
    pld
    rts
