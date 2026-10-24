.setcpu "65816"
.segment "CODE"
.org $0C16
map_control_0f0c16:
    .byte $E8 ; backreference distance high bits
    .byte $2E ; distance low bit/count
