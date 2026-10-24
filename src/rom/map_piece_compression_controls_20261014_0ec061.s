.setcpu "65816"
.segment "CODE"
.org $C061
map_control_0ec061:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
