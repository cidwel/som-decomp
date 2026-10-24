.setcpu "65816"
.segment "CODE"
.org $AAC2
map_control_0daac2:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
