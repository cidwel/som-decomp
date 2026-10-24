.setcpu "65816"
.segment "CODE"
.org $60F8
map_control_0d60f8:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
