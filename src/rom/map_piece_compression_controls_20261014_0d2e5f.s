.setcpu "65816"
.segment "CODE"
.org $2E5F
map_control_0d2e5f:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
