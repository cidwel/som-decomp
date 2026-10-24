.setcpu "65816"
.segment "CODE"
.org $AB6F
map_control_0eab6f:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
