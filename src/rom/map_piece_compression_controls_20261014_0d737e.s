.setcpu "65816"
.segment "CODE"
.org $737E
map_control_0d737e:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $26 ; distance low bit/count
