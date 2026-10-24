.setcpu "65816"
.segment "CODE"
.org $AA22
map_control_0daa22:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
