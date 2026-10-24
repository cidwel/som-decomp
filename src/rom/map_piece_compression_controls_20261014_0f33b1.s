.setcpu "65816"
.segment "CODE"
.org $33B1
map_control_0f33b1:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
