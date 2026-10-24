.setcpu "65816"
.segment "CODE"
.org $2C79
map_control_0e2c79:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
