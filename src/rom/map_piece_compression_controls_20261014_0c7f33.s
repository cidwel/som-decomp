.setcpu "65816"
.segment "CODE"
.org $7F33
map_control_0c7f33:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
