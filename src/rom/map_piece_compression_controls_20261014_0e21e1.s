.setcpu "65816"
.segment "CODE"
.org $21E1
map_control_0e21e1:
    .byte $EC ; backreference distance high bits
    .byte $90 ; distance low bit/count
