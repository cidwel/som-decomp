.setcpu "65816"
.segment "CODE"
.org $AB81
map_control_0eab81:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
