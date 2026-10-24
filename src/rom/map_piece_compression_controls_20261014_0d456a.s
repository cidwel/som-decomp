.setcpu "65816"
.segment "CODE"
.org $456A
map_control_0d456a:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
