.setcpu "65816"
.segment "CODE"
.org $E0C9
map_control_0de0c9:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
