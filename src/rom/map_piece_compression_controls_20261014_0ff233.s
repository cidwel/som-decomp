.setcpu "65816"
.segment "CODE"
.org $F233
map_control_0ff233:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
