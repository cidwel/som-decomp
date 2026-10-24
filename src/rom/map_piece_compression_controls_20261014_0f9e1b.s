.setcpu "65816"
.segment "CODE"
.org $9E1B
map_control_0f9e1b:
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
