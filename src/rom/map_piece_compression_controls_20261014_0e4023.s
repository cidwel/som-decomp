.setcpu "65816"
.segment "CODE"
.org $4023
map_control_0e4023:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
