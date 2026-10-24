.setcpu "65816"
.segment "CODE"
.org $91A7
map_control_0f91a7:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
