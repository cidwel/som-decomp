.setcpu "65816"
.segment "CODE"
.org $08F2
map_control_0f08f2:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
