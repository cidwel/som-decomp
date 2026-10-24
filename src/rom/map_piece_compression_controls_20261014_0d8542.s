.setcpu "65816"
.segment "CODE"
.org $8542
map_control_0d8542:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
