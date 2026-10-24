.setcpu "65816"
.segment "CODE"
.org $5649
map_control_0e5649:
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
