.setcpu "65816"
.segment "CODE"
.org $EE73
map_control_0fee73:
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
