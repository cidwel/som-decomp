.setcpu "65816"
.segment "CODE"
.org $0B04
map_control_0e0b04:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
