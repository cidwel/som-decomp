.setcpu "65816"
.segment "CODE"
.org $6F0A
map_control_0d6f0a:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
