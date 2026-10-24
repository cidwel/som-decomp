.setcpu "65816"
.segment "CODE"
.org $0E16
map_control_0d0e16:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
