.setcpu "65816"
.segment "CODE"
.org $19A4
map_control_0d19a4:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
