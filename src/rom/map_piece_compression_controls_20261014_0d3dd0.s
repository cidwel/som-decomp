.setcpu "65816"
.segment "CODE"
.org $3DD0
map_control_0d3dd0:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
