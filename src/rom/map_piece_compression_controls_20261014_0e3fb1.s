.setcpu "65816"
.segment "CODE"
.org $3FB1
map_control_0e3fb1:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
