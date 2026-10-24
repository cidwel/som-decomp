.setcpu "65816"
.segment "CODE"
.org $12E4
map_control_0f12e4:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
