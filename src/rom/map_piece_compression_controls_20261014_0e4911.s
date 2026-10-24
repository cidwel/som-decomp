.setcpu "65816"
.segment "CODE"
.org $4911
map_control_0e4911:
    .byte $EF ; backreference distance high bits
    .byte $93 ; distance low bit/count
