.setcpu "65816"
.segment "CODE"
.org $9505
map_control_0d9505:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
