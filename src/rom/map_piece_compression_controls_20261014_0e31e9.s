.setcpu "65816"
.segment "CODE"
.org $31E9
map_control_0e31e9:
    .byte $ED ; backreference distance high bits
    .byte $04 ; distance low bit/count
