.setcpu "65816"
.segment "CODE"
.org $0D72
map_control_0f0d72:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
