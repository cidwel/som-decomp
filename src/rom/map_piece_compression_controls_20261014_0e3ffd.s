.setcpu "65816"
.segment "CODE"
.org $3FFD
map_control_0e3ffd:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
