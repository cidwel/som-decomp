.setcpu "65816"
.segment "CODE"
.org $E4B9
map_control_0fe4b9:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
