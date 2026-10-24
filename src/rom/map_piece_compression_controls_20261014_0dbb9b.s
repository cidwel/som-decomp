.setcpu "65816"
.segment "CODE"
.org $BB9B
map_control_0dbb9b:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
