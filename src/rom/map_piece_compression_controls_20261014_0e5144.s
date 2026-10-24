.setcpu "65816"
.segment "CODE"
.org $5144
map_control_0e5144:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
