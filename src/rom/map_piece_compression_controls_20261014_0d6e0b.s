.setcpu "65816"
.segment "CODE"
.org $6E0B
map_control_0d6e0b:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
