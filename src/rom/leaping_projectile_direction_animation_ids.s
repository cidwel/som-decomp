; Numeric projectile state/direction metadata; see docs/graphics.md.
.setcpu "65816"
.segment "CODE"
.org $E525
leaping_projectile_direction_animation_ids:
 .repeat 2
    .word $0106, $0105, $0104, $0105
 .endrepeat
