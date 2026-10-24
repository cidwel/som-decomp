.setcpu "65816"
.segment "CODE"
.org $403E
map_control_0e403e:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
