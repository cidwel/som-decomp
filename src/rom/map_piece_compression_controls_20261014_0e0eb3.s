.setcpu "65816"
.segment "CODE"
.org $0EB3
map_control_0e0eb3:
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
