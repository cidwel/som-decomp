.setcpu "65816"
.segment "CODE"
.org $81E0
map_control_0d81e0:
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $47 ; distance low bit/count
