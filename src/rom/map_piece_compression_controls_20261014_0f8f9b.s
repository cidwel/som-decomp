.setcpu "65816"
.segment "CODE"
.org $8F9B
map_control_0f8f9b:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
