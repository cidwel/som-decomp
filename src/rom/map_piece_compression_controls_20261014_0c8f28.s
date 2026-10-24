.setcpu "65816"
.segment "CODE"
.org $8F28
map_control_0c8f28:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
