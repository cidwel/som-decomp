.setcpu "65816"
.segment "CODE"
.org $2E84
map_control_0f2e84:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
