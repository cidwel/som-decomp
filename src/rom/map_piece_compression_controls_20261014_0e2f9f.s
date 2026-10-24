.setcpu "65816"
.segment "CODE"
.org $2F9F
map_control_0e2f9f:
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
