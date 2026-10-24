.setcpu "65816"
.segment "CODE"
.org $9691
map_control_0e9691:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
