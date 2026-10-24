; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-trail-state.md.
.setcpu "65816"
.smart
.a8
.i16

send_spell_entity_positional_sound = $376A

.segment "CODE"
.org $2EBD
send_spell_entity_positional_sound_long:
    jsr send_spell_entity_positional_sound
    rtl
