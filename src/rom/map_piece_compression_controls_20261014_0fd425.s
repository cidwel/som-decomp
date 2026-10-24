.setcpu "65816"
.segment "CODE"
.org $D425
map_control_0fd425:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
