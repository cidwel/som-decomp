.setcpu "65816"
.segment "CODE"
.org $8543
map_control_0e8543:
    .byte $E8 ; backreference distance high bits
    .byte $76 ; distance low bit/count
