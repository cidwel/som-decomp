.setcpu "65816"
.segment "CODE"
.org $19EF
map_control_0f19ef:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
