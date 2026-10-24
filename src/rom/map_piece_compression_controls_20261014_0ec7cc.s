.setcpu "65816"
.segment "CODE"
.org $C7CC
map_control_0ec7cc:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
