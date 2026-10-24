.setcpu "65816"
.segment "CODE"
.org $0CBF
map_control_0e0cbf:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
