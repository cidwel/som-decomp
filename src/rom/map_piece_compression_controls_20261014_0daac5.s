.setcpu "65816"
.segment "CODE"
.org $AAC5
map_control_0daac5:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
