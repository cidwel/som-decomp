.setcpu "65816"
.segment "CODE"
.org $08F4
map_control_0d08f4:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
