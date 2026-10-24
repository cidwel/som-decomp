.setcpu "65816"
.segment "CODE"
.org $88B8
map_control_0f88b8:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
