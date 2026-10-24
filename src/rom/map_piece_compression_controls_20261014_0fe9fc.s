.setcpu "65816"
.segment "CODE"
.org $E9FC
map_control_0fe9fc:
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
