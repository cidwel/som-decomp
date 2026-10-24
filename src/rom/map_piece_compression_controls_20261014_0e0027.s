.setcpu "65816"
.segment "CODE"
.org $0027
map_control_0e0027:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
