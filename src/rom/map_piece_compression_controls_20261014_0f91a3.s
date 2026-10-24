.setcpu "65816"
.segment "CODE"
.org $91A3
map_control_0f91a3:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
