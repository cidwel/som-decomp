.setcpu "65816"
.segment "CODE"
.org $0F09
map_control_0e0f09:
    .byte $E8 ; backreference distance high bits
    .byte $6E ; distance low bit/count
