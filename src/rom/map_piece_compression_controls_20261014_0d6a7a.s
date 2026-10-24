.setcpu "65816"
.segment "CODE"
.org $6A7A
map_control_0d6a7a:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
