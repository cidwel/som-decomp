.setcpu "65816"
.segment "CODE"
.org $C6ED
map_control_0ec6ed:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
