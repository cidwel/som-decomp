.setcpu "65816"
.segment "CODE"
.org $D144
map_control_0ed144:
    .byte $EC ; backreference distance high bits
    .byte $05 ; distance low bit/count
