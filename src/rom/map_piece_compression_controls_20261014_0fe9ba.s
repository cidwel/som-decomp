.setcpu "65816"
.segment "CODE"
.org $E9BA
map_control_0fe9ba:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
