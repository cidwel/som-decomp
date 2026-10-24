.setcpu "65816"
.segment "CODE"
.org $9D52
map_control_0e9d52:
    .byte $E8 ; backreference distance high bits
    .byte $91 ; distance low bit/count
