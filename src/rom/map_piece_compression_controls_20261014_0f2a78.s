.setcpu "65816"
.segment "CODE"
.org $2A78
map_control_0f2a78:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
