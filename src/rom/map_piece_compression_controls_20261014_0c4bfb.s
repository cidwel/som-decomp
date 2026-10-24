.setcpu "65816"
.segment "CODE"
.org $4BFB
map_control_0c4bfb:
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count
