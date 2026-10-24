.setcpu "65816"
.segment "CODE"
.org $0F02
map_control_0e0f02:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $38 ; distance low bit/count
