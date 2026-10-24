.setcpu "65816"
.segment "CODE"
.org $0EF0
map_control_0f0ef0:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
