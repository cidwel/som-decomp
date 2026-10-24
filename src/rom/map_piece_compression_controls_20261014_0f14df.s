.setcpu "65816"
.segment "CODE"
.org $14DF
map_control_0f14df:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
