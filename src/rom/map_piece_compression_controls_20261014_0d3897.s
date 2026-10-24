.setcpu "65816"
.segment "CODE"
.org $3897
map_control_0d3897:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
