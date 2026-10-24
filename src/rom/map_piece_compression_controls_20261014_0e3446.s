.setcpu "65816"
.segment "CODE"
.org $3446
map_control_0e3446:
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
