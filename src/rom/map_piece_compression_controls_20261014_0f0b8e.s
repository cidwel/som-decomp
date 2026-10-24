.setcpu "65816"
.segment "CODE"
.org $0B8E
map_control_0f0b8e:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
