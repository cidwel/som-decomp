.setcpu "65816"
.segment "CODE"
.org $7ACF
map_control_0c7acf:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
