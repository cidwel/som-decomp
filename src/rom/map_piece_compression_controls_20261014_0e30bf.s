.setcpu "65816"
.segment "CODE"
.org $30BF
map_control_0e30bf:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
