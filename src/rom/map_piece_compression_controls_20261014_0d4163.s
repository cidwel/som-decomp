.setcpu "65816"
.segment "CODE"
.org $4163
map_control_0d4163:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
