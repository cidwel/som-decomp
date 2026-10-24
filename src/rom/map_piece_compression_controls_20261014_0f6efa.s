.setcpu "65816"
.segment "CODE"
.org $6EFA
map_control_0f6efa:
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
