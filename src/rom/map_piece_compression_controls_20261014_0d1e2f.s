.setcpu "65816"
.segment "CODE"
.org $1E2F
map_control_0d1e2f:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
