.setcpu "65816"
.segment "CODE"
.org $33F9
map_control_0e33f9:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
