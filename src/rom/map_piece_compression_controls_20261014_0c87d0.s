.setcpu "65816"
.segment "CODE"
.org $87D0
map_control_0c87d0:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
