.setcpu "65816"
.segment "CODE"
.org $522A
map_control_0e522a:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
