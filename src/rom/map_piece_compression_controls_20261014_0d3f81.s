.setcpu "65816"
.segment "CODE"
.org $3F81
map_control_0d3f81:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
