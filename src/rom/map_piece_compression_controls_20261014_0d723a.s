.setcpu "65816"
.segment "CODE"
.org $723A
map_control_0d723a:
    .byte $E8 ; backreference distance high bits
    .byte $19 ; distance low bit/count
