.setcpu "65816"
.segment "CODE"
.org $9681
map_control_0e9681:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
