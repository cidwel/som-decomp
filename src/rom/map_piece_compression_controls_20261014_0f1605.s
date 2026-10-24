.setcpu "65816"
.segment "CODE"
.org $1605
map_control_0f1605:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
