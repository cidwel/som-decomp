.setcpu "65816"
.segment "CODE"
.org $290D
map_control_0d290d:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
