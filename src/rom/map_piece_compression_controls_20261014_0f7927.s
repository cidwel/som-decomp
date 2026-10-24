.setcpu "65816"
.segment "CODE"
.org $7927
map_control_0f7927:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
