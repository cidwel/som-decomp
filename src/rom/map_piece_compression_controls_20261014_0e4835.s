.setcpu "65816"
.segment "CODE"
.org $4835
map_control_0e4835:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
