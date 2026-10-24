.setcpu "65816"
.segment "CODE"
.org $3764
map_control_0e3764:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
