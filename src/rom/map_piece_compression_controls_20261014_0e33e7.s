.setcpu "65816"
.segment "CODE"
.org $33E7
map_control_0e33e7:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
