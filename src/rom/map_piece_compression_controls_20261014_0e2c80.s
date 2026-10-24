.setcpu "65816"
.segment "CODE"
.org $2C80
map_control_0e2c80:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
