.setcpu "65816"
.segment "CODE"
.org $38D5
map_control_0c38d5:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
