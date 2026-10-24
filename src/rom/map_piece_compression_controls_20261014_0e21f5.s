.setcpu "65816"
.segment "CODE"
.org $21F5
map_control_0e21f5:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
