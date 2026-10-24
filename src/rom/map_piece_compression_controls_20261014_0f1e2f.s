.setcpu "65816"
.segment "CODE"
.org $1E2F
map_control_0f1e2f:
    .byte $E8 ; backreference distance high bits
    .byte $22 ; distance low bit/count
