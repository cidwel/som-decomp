.setcpu "65816"
.segment "CODE"
.org $D0AB
map_control_0ed0ab:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
