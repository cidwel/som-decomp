.setcpu "65816"
.segment "CODE"
.org $74A5
map_control_0e74a5:
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
