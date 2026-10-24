.setcpu "65816"
.segment "CODE"
.org $273A
map_control_0c273a:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
