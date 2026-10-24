.setcpu "65816"
.segment "CODE"
.org $8A29
map_control_0c8a29:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
