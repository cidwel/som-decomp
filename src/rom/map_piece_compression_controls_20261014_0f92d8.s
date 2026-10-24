.setcpu "65816"
.segment "CODE"
.org $92D8
map_control_0f92d8:
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
