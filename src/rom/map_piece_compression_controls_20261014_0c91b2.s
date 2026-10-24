.setcpu "65816"
.segment "CODE"
.org $91B2
map_control_0c91b2:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
