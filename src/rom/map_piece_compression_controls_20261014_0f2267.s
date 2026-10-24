.setcpu "65816"
.segment "CODE"
.org $2267
map_control_0f2267:
    .byte $E8 ; backreference distance high bits
    .byte $5D ; distance low bit/count
