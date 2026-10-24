.setcpu "65816"
.segment "CODE"
.org $E50D
map_control_0de50d:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
