.setcpu "65816"
.segment "CODE"
.org $40C2
map_control_0f40c2:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
