.setcpu "65816"
.segment "CODE"
.org $8EBF
map_control_0f8ebf:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
