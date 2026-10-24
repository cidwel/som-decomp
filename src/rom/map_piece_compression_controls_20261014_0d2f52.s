.setcpu "65816"
.segment "CODE"
.org $2F52
map_control_0d2f52:
    .byte $E9 ; backreference distance high bits
    .byte $05 ; distance low bit/count
