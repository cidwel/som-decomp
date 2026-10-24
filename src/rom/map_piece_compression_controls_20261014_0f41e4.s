.setcpu "65816"
.segment "CODE"
.org $41E4
map_control_0f41e4:
    .byte $E9 ; backreference distance high bits
    .byte $05 ; distance low bit/count
