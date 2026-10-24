.setcpu "65816"
.segment "CODE"
.org $4E51
map_control_0d4e51:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
