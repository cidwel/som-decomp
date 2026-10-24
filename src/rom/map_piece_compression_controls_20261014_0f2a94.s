.setcpu "65816"
.segment "CODE"
.org $2A94
map_control_0f2a94:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
