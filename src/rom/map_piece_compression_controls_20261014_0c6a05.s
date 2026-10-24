.setcpu "65816"
.segment "CODE"
.org $6A05
map_control_0c6a05:
    .byte $E8 ; backreference distance high bits
    .byte $19 ; distance low bit/count
