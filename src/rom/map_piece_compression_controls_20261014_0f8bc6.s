.setcpu "65816"
.segment "CODE"
.org $8BC6
map_control_0f8bc6:
    .byte $E8 ; backreference distance high bits
    .byte $9D ; distance low bit/count
