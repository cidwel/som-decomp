.setcpu "65816"
.segment "CODE"
.org $4C77
map_control_0c4c77:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
