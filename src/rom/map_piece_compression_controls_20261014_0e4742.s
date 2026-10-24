.setcpu "65816"
.segment "CODE"
.org $4742
map_control_0e4742:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
