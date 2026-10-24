.setcpu "65816"
.segment "CODE"
.org $73C8
map_control_0c73c8:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
