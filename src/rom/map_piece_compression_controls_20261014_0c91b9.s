.setcpu "65816"
.segment "CODE"
.org $91B9
map_control_0c91b9:
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
