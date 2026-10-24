.setcpu "65816"
.segment "CODE"
.org $4A1C
map_control_0e4a1c:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
