.setcpu "65816"
.segment "CODE"
.org $91E0
map_control_0f91e0:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
