.setcpu "65816"
.segment "CODE"
.org $3CA8
map_control_0e3ca8:
    .byte $EF ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $19 ; distance low bit/count
