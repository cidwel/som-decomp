.setcpu "65816"
.segment "CODE"
.org $8B07
map_control_0f8b07:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
