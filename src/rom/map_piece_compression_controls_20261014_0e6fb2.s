.setcpu "65816"
.segment "CODE"
.org $6FB2
map_control_0e6fb2:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
