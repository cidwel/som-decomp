.setcpu "65816"
.segment "CODE"
.org $5716
map_control_0d5716:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
