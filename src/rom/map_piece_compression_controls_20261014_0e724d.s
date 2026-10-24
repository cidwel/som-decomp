.setcpu "65816"
.segment "CODE"
.org $724D
map_control_0e724d:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
