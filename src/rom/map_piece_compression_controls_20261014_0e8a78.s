.setcpu "65816"
.segment "CODE"
.org $8A78
map_control_0e8a78:
    .byte $EC ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1D ; distance low bit/count
