.setcpu "65816"
.segment "CODE"
.org $2E4D
map_control_0f2e4d:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
