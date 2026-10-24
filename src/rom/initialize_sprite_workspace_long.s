; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-sprite-publication.md.
.setcpu "65816"
.smart
.a8
.i16

initialize_map_sprite_workspace = $E355

.segment "CODE"
.org $E351
initialize_sprite_workspace_long:
    jsr initialize_map_sprite_workspace
    rtl
