.setcpu "65816"
.segment "CODE"
.org $DDD1
map_control_0fddd1:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
