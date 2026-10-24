.setcpu "65816"
.segment "CODE"
.org $30F4
map_control_0e30f4:
    .byte $E8 ; backreference distance high bits
    .byte $9D ; distance low bit/count
