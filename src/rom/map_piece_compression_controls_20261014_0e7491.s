.setcpu "65816"
.segment "CODE"
.org $7491
map_control_0e7491:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
