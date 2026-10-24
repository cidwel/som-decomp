; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-graphics-audio.md.
.setcpu "65816"
.smart
.a8
.i16

dispatch_explicit_graphics_plane_conversion = $C583

.segment "CODE"
.org $8009
graphics_planes_public_jump:
    jmp dispatch_explicit_graphics_plane_conversion
