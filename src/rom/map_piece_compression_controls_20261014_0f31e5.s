.setcpu "65816"
.segment "CODE"
.org $31E5
map_control_0f31e5:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
