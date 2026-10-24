; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-entity-index-bits.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $4398
calculate_spell_entity_heap_slot_index:
    phd
    php
    rep #$20
    sep #$20
    phb
    .a8
    lda #$7E
    pha
    plb
    rep #$20
    txa
    sec
    sbc a:$8424
    lsr
    lsr
    lsr
    lsr
    lsr
    .a16
    and #$0007
    plb
    plp
    pld
    rts
