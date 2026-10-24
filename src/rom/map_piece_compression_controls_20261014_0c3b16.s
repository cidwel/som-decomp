.setcpu "65816"
.segment "CODE"
.org $3B16
map_control_0c3b16:
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
