.setcpu "65816"
.segment "CODE"
.org $E7E5
map_control_0de7e5:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
