.setcpu "65816"
.segment "CODE"
.org $0E61
map_control_0f0e61:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
