.setcpu "65816"
.segment "CODE"
.org $33E0
map_control_0e33e0:
    .byte $E8 ; backreference distance high bits
    .byte $76 ; distance low bit/count
