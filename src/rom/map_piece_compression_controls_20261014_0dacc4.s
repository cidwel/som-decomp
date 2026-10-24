.setcpu "65816"
.segment "CODE"
.org $ACC4
map_control_0dacc4:
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
