; Numeric projectile state/direction metadata; see docs/graphics.md.
.setcpu "65816"
.segment "CODE"
.org $E535
leaping_projectile_direction_orientation_bits:
    .word $0000, $0080, $0080, $00C0, $0040, $0040, $0000, $0000
