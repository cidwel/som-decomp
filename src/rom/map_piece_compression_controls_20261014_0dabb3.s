.setcpu "65816"
.segment "CODE"
.org $ABB3
map_control_0dabb3:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
