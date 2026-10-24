.setcpu "65816"
.segment "CODE"
.org $01E1
map_control_0f01e1:
    .byte $E9 ; backreference distance high bits
    .byte $12 ; distance low bit/count
