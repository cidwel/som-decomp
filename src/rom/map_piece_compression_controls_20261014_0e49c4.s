.setcpu "65816"
.segment "CODE"
.org $49C4
map_control_0e49c4:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
