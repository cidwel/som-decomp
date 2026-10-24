.setcpu "65816"
.segment "CODE"
.org $B6DB
map_control_0eb6db:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
