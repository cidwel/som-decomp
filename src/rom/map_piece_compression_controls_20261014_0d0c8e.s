.setcpu "65816"
.segment "CODE"
.org $0C8E
map_control_0d0c8e:
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $52 ; distance low bit/count
