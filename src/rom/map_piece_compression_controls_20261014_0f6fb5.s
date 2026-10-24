.setcpu "65816"
.segment "CODE"
.org $6FB5
map_control_0f6fb5:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
