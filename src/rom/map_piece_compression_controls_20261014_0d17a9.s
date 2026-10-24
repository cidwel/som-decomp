.setcpu "65816"
.segment "CODE"
.org $17A9
map_control_0d17a9:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
