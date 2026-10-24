; Numeric projectile state/direction metadata; see docs/graphics.md.
.setcpu "65816"
acceleration = 2
.segment "CODE"
.org $E545
leaping_projectile_eight_direction_accelerations:
    .word acceleration, 0
    .word acceleration, acceleration
    .word 0, acceleration
    .word (-acceleration & $FFFF), acceleration
    .word (-acceleration & $FFFF), 0
    .word (-acceleration & $FFFF), (-acceleration & $FFFF)
    .word 0, (-acceleration & $FFFF)
    .word acceleration, (-acceleration & $FFFF)
