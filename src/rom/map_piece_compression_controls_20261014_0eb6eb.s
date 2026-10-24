.setcpu "65816"
.segment "CODE"
.org $B6EB
map_control_0eb6eb:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
