.setcpu "65816"
.segment "CODE"
.org $922D
map_control_0c922d:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
