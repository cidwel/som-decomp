.setcpu "65816"
.segment "CODE"
.org $46B5
map_control_0c46b5:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
