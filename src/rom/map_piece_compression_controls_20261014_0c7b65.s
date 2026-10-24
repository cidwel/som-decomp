.setcpu "65816"
.segment "CODE"
.org $7B65
map_control_0c7b65:
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
