.setcpu "65816"
.segment "CODE"
.org $EA35
map_control_0eea35:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
