.setcpu "65816"
.segment "CODE"
.org $7720
map_control_0f7720:
    .byte $E9 ; backreference distance high bits
    .byte $8F ; distance low bit/count
