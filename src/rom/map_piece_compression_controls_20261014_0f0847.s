.setcpu "65816"
.segment "CODE"
.org $0847
map_control_0f0847:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
