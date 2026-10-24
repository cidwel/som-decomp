.setcpu "65816"
.segment "CODE"
.org $2E52
map_control_0d2e52:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
