.setcpu "65816"
.segment "CODE"
.org $8F75
map_control_0d8f75:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
