.setcpu "65816"
.segment "CODE"
.org $292E
map_control_0f292e:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
