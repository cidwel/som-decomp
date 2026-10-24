.setcpu "65816"
.segment "CODE"
.org $8617
map_control_0f8617:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
