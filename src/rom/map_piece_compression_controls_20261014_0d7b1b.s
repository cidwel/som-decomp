.setcpu "65816"
.segment "CODE"
.org $7B1B
map_control_0d7b1b:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
