.setcpu "65816"
.segment "CODE"
.org $D0C0
map_control_0ed0c0:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
