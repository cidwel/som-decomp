.setcpu "65816"
.segment "CODE"
.org $95F9
map_control_0e95f9:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
