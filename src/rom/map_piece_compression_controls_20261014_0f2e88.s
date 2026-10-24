.setcpu "65816"
.segment "CODE"
.org $2E88
map_control_0f2e88:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
