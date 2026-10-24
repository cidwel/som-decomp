.setcpu "65816"
.segment "CODE"
.org $E41A
map_control_0fe41a:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
