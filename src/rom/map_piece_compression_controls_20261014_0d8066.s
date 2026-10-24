.setcpu "65816"
.segment "CODE"
.org $8066
map_control_0d8066:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
