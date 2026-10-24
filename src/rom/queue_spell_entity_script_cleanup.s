; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-construction.md.
.setcpu "65816"
.smart
.a8
.i16

build_spell_entity_script_transfers = $302E

.segment "CODE"
.org $39BA
queue_spell_entity_script_cleanup:
    phd
    php
    rep #$20
    ldx a:$8234
    .i16
    ldy #$FC7C
    .a16
    lda #$0006
    jsr build_spell_entity_script_transfers
    plp
    pld
    rts
