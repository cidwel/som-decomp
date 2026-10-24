.setcpu "65816"
.segment "CODE"
.org $7B36
map_control_0d7b36:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
