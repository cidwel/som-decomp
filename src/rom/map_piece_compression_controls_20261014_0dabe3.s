.setcpu "65816"
.segment "CODE"
.org $ABE3
map_control_0dabe3:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
