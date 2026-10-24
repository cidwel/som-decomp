.setcpu "65816"
.segment "CODE"
.org $E362
map_control_0fe362:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
