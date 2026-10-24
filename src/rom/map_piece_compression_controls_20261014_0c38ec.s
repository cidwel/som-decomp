.setcpu "65816"
.segment "CODE"
.org $38EC
map_control_0c38ec:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
