.setcpu "65816"
.segment "CODE"
.org $EF5D
map_control_0fef5d:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
