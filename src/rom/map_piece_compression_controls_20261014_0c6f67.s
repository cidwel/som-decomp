.setcpu "65816"
.segment "CODE"
.org $6F67
map_control_0c6f67:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
