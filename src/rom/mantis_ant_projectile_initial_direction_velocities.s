; Eight signed-word XY velocities read by C23E7F.
.setcpu "65816"
.segment "CODE"
.org $E028
mantis_ant_projectile_initial_direction_velocities:
    .word $0002, $0002
    .word $0002, $0002
    .word $0000, $0002
    .word $FFFE, $0002
    .word $FFFE, $0002
    .word $FFFE, $0002
    .word $0000, $0002
    .word $0002, $0002
