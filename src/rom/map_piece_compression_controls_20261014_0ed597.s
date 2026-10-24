.setcpu "65816"
.segment "CODE"
.org $D597
map_control_0ed597:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
