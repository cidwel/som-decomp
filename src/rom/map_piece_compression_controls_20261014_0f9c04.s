.setcpu "65816"
.segment "CODE"
.org $9C04
map_control_0f9c04:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
