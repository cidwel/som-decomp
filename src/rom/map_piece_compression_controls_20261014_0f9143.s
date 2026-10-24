.setcpu "65816"
.segment "CODE"
.org $9143
map_control_0f9143:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
