.setcpu "65816"
.segment "CODE"
.org $F437
map_control_0ff437:
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
