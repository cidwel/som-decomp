.setcpu "65816"
.segment "CODE"
.org $E7E8
map_control_0de7e8:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
