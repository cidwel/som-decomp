.setcpu "65816"
.segment "CODE"
.org $B588
map_control_0fb588:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
