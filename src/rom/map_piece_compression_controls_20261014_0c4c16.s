.setcpu "65816"
.segment "CODE"
.org $4C16
map_control_0c4c16:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
