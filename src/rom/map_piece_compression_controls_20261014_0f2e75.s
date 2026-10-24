.setcpu "65816"
.segment "CODE"
.org $2E75
map_control_0f2e75:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
