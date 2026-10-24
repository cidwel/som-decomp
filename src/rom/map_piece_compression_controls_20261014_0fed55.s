.setcpu "65816"
.segment "CODE"
.org $ED55
map_control_0fed55:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
