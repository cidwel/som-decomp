.setcpu "65816"
.segment "CODE"
.org $633B
map_control_0d633b:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
