.setcpu "65816"
.segment "CODE"
.org $9748
map_control_0e9748:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
