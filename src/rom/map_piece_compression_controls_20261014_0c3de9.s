.setcpu "65816"
.segment "CODE"
.org $3DE9
map_control_0c3de9:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
