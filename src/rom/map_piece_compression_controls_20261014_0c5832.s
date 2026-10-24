.setcpu "65816"
.segment "CODE"
.org $5832
map_control_0c5832:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
