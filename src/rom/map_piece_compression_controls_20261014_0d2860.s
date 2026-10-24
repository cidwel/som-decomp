.setcpu "65816"
.segment "CODE"
.org $2860
map_control_0d2860:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
