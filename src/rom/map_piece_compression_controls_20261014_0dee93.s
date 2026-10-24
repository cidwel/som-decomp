.setcpu "65816"
.segment "CODE"
.org $EE93
map_control_0dee93:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
