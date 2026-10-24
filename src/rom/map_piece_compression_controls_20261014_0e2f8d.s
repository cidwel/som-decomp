.setcpu "65816"
.segment "CODE"
.org $2F8D
map_control_0e2f8d:
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
