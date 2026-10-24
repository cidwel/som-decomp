.setcpu "65816"
.segment "CODE"
.org $30EA
map_control_0e30ea:
    .byte $E8 ; backreference distance high bits
    .byte $9B ; distance low bit/count
