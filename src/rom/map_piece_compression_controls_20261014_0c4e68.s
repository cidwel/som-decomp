.setcpu "65816"
.segment "CODE"
.org $4E68
map_control_0c4e68:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
