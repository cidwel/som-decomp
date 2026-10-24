.setcpu "65816"
.segment "CODE"
.org $4C90
map_control_0d4c90:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
