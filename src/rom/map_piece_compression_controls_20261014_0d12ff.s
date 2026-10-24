.setcpu "65816"
.segment "CODE"
.org $12FF
map_control_0d12ff:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
