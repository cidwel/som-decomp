.setcpu "65816"
.segment "CODE"
.org $304F
map_control_0f304f:
    .byte $E8 ; backreference distance high bits
    .byte $91 ; distance low bit/count
