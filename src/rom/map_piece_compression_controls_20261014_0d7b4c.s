.setcpu "65816"
.segment "CODE"
.org $7B4C
map_control_0d7b4c:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
