.setcpu "65816"
.segment "CODE"
.org $EB7E
map_control_0feb7e:
    .byte $EF ; backreference distance high bits
    .byte $0E ; distance low bit/count
