.setcpu "65816"
.segment "CODE"
.org $43DF
map_control_0d43df:
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $93 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $08 ; distance low bit/count
