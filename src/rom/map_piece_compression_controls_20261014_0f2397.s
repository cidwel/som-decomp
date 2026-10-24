.setcpu "65816"
.segment "CODE"
.org $2397
map_control_0f2397:
    .byte $ED ; backreference distance high bits
    .byte $94 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
