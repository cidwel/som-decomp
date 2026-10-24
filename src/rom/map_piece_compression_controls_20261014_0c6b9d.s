.setcpu "65816"
.segment "CODE"
.org $6B9D
map_control_0c6b9d:
    .byte $E8 ; backreference distance high bits
    .byte $43 ; distance low bit/count
