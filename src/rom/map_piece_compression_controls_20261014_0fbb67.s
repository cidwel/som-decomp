.setcpu "65816"
.segment "CODE"
.org $BB67
map_control_0fbb67:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
