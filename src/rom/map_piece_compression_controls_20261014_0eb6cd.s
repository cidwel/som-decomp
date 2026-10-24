.setcpu "65816"
.segment "CODE"
.org $B6CD
map_control_0eb6cd:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
