.setcpu "65816"
.segment "CODE"
.org $21C6
map_control_0e21c6:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
