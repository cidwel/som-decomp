; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-graphics-audio.md.
.setcpu "65816"
.smart
.a8
.i16

convert_object_graphics_planes_inverted = $C8A9
convert_object_graphics_planes_masked = $C5D1
convert_object_graphics_planes_xor = $C731

.segment "CODE"
.org $C583
dispatch_explicit_graphics_plane_conversion:
    sep #$20
    sta $08
    xba
    bne dispatch_explicit_graphics_plane_conversion_c1c58e
    jsr convert_object_graphics_planes_masked
    rtl
dispatch_explicit_graphics_plane_conversion_c1c58e:
    dec
    bne dispatch_explicit_graphics_plane_conversion_c1c595
    jsr convert_object_graphics_planes_xor
    rtl
dispatch_explicit_graphics_plane_conversion_c1c595:
    jsr convert_object_graphics_planes_inverted
    rtl
