.setcpu "65816"
.segment "CODE"
.org $E029
map_control_0de029:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
