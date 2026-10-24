; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-sprite-publication.md.
.setcpu "65816"
.smart
.a8
.i16

emit_cast_sprite_workspace = $E32C

.segment "CODE"
.org $E328
cast_sprite_emission_long:
    jsr emit_cast_sprite_workspace
    rtl
