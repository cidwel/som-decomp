.setcpu "65816"
.segment "CODE"
.org $3A52
map_control_0f3a52:
    .byte $E8 ; backreference distance high bits
    .byte $C1 ; distance low bit/count
