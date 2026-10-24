; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-map-terrain-queries.md.
.setcpu "65816"
.smart
.a8
.i16

test_actor_horizontal_footprint_and_redirect_step = $B9EA
test_actor_vertical_footprint_and_redirect_step = $BAE2

.segment "CODE"
.org $BC2C
require_both_actor_footprint_axes_clear:
    sec
    jsr test_actor_horizontal_footprint_and_redirect_step
    bcs require_both_actor_footprint_axes_clear_c1bc36
    sec
    jsr test_actor_vertical_footprint_and_redirect_step
require_both_actor_footprint_axes_clear_c1bc36:
    rts
