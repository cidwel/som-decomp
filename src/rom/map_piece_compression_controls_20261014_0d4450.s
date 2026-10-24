.setcpu "65816"
.segment "CODE"
.org $4450
map_control_0d4450:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
