.setcpu "65816"
.segment "CODE"
.org $ED03
map_control_0fed03:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
