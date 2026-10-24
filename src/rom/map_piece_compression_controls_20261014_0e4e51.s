.setcpu "65816"
.segment "CODE"
.org $4E51
map_control_0e4e51:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
