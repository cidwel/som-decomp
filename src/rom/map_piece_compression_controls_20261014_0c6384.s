.setcpu "65816"
.segment "CODE"
.org $6384
map_control_0c6384:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
