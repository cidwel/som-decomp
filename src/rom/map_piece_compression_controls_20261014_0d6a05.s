.setcpu "65816"
.segment "CODE"
.org $6A05
map_control_0d6a05:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
