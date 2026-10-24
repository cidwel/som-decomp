.setcpu "65816"
.segment "CODE"
.org $B5C0
map_control_0eb5c0:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
