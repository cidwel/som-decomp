.setcpu "65816"
.segment "CODE"
.org $59D8
map_control_0c59d8:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
