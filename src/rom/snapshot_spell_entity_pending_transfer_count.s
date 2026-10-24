; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-queue.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $2A4D
snapshot_spell_entity_pending_transfer_count:
    phd
    php
    rep #$20
    sep #$20
    lda a:$821A
    sta a:$821C
    plp
    pld
    rts
