.setcpu "65816"
.segment "CODE"
.org $D927
map_control_0dd927:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
