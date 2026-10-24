.setcpu "65816"
.segment "CODE"
.org $EFED
map_control_0fefed:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
