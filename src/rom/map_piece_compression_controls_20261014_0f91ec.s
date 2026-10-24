.setcpu "65816"
.segment "CODE"
.org $91EC
map_control_0f91ec:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
