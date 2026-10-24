.setcpu "65816"
.segment "CODE"
.org $0FFB
map_control_0e0ffb:
    .byte $ED ; backreference distance high bits
    .byte $09 ; distance low bit/count
