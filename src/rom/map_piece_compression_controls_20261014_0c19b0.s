.setcpu "65816"
.segment "CODE"
.org $19B0
map_control_0c19b0:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
