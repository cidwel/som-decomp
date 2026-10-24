; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

release_auxiliary_graphics_buffers = $8363
release_colour_scene = $BF10
release_colour_tree = $A07B
release_low_colour_scene_template = $994D

.segment "CODE"
.org $9660
release_colour_resources:
    phd
    php
    rep #$30
    sep #$20
    jsr release_low_colour_scene_template
    jsr release_auxiliary_graphics_buffers
    jsr release_colour_tree
    jsr release_colour_scene
    plp
    pld
    rts
