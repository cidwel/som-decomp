.setcpu "65816"
.segment "CODE"
.org $8071
map_control_0d8071:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
