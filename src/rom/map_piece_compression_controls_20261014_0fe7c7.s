.setcpu "65816"
.segment "CODE"
.org $E7C7
map_control_0fe7c7:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
