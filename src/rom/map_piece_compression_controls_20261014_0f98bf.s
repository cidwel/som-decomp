.setcpu "65816"
.segment "CODE"
.org $98BF
map_control_0f98bf:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
