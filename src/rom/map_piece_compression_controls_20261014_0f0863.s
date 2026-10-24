.setcpu "65816"
.segment "CODE"
.org $0863
map_control_0f0863:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
