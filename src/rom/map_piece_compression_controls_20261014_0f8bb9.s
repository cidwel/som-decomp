.setcpu "65816"
.segment "CODE"
.org $8BB9
map_control_0f8bb9:
    .byte $E8 ; backreference distance high bits
    .byte $9D ; distance low bit/count
