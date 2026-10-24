.setcpu "65816"
.segment "CODE"
.org $AE8C
map_control_0dae8c:
    .byte $EF ; backreference distance high bits
    .byte $06 ; distance low bit/count
