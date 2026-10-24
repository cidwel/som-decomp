.setcpu "65816"
.segment "CODE"
.org $8848
map_control_0e8848:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $91 ; distance low bit/count
