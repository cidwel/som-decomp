.setcpu "65816"
.segment "CODE"
.org $5100
map_control_0d5100:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
