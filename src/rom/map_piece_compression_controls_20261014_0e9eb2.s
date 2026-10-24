.setcpu "65816"
.segment "CODE"
.org $9EB2
map_control_0e9eb2:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
