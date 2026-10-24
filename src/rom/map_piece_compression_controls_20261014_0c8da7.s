.setcpu "65816"
.segment "CODE"
.org $8DA7
map_control_0c8da7:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
