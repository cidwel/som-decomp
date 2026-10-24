.setcpu "65816"
.segment "CODE"
.org $5B96
map_control_0e5b96:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
