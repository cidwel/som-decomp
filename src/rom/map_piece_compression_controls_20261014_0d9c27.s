.setcpu "65816"
.segment "CODE"
.org $9C27
map_control_0d9c27:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
