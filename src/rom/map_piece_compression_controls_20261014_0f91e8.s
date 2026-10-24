.setcpu "65816"
.segment "CODE"
.org $91E8
map_control_0f91e8:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
