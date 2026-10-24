; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_auxiliary_graphics_buffers = $833E
allocate_colour_tree = $A061
initialize_low_colour_scene_template = $991C
prepare_colour_scene = $BE5B

.segment "CODE"
.org $964B
prepare_colour_resources:
    phd
    php
    rep #$30
    sep #$20
    jsr prepare_colour_scene
    jsr allocate_colour_tree
    jsr allocate_auxiliary_graphics_buffers
    jsr initialize_low_colour_scene_template
    plp
    pld
    rts
