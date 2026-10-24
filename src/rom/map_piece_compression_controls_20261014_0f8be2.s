.setcpu "65816"
.segment "CODE"
.org $8BE2
map_control_0f8be2:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8F ; distance low bit/count
