.setcpu "65816"
.segment "CODE"
.org $3E19
map_control_0c3e19:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
