.setcpu "65816"
.segment "CODE"
.org $C9E0
map_control_0ec9e0:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
