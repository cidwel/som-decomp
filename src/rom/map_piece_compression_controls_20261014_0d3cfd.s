.setcpu "65816"
.segment "CODE"
.org $3CFD
map_control_0d3cfd:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
