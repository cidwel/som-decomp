.setcpu "65816"
.segment "CODE"
.org $8998
map_control_0d8998:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
