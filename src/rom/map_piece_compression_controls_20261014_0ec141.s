.setcpu "65816"
.segment "CODE"
.org $C141
map_control_0ec141:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
