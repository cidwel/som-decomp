.setcpu "65816"
.segment "CODE"
.org $56AF
map_control_0e56af:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
