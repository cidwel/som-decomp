.setcpu "65816"
.segment "CODE"
.org $4D43
map_control_0c4d43:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
