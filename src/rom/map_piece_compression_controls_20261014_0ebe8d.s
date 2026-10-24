.setcpu "65816"
.segment "CODE"
.org $BE8D
map_control_0ebe8d:
    .byte $E8 ; backreference distance high bits
    .byte $AD ; distance low bit/count
