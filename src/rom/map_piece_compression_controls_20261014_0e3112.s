.setcpu "65816"
.segment "CODE"
.org $3112
map_control_0e3112:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
