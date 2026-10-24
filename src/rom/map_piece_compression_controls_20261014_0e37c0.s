.setcpu "65816"
.segment "CODE"
.org $37C0
map_control_0e37c0:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
