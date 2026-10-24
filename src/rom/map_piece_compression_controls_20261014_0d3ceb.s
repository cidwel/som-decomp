.setcpu "65816"
.segment "CODE"
.org $3CEB
map_control_0d3ceb:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
