.setcpu "65816"
.segment "CODE"
.org $C81A
map_control_0ec81a:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
