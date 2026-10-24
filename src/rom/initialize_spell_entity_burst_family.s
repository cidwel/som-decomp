; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-burst-init.md.
.setcpu "65816"
.smart
.a8
.i16

initialize_spell_entity_burst_sprites_long = $D3EA00

.segment "CODE"
.org $2800
initialize_spell_entity_burst_family:
    jsl f:initialize_spell_entity_burst_sprites_long
    rts
