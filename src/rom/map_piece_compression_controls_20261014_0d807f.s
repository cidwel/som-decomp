.setcpu "65816"
.segment "CODE"
.org $807F
map_control_0d807f:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
