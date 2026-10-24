.setcpu "65816"
.segment "CODE"
.org $4341
map_control_0d4341:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $08 ; distance low bit/count
