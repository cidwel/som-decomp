.setcpu "65816"
.segment "CODE"
.org $2428
map_control_0e2428:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
