.setcpu "65816"
.segment "CODE"
.org $12BD
map_control_0d12bd:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
