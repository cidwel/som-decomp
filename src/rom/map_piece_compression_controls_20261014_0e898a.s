.setcpu "65816"
.segment "CODE"
.org $898A
map_control_0e898a:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
