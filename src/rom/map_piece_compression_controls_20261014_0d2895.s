.setcpu "65816"
.segment "CODE"
.org $2895
map_control_0d2895:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
