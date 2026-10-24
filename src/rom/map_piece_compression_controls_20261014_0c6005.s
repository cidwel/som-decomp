.setcpu "65816"
.segment "CODE"
.org $6005
map_control_0c6005:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
