.setcpu "65816"
.segment "CODE"
.org $3156
map_control_0f3156:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
