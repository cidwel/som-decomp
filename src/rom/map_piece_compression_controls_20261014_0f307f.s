.setcpu "65816"
.segment "CODE"
.org $307F
map_control_0f307f:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
