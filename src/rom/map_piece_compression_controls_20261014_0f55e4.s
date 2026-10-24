.setcpu "65816"
.segment "CODE"
.org $55E4
map_control_0f55e4:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
