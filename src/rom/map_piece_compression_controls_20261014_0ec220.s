.setcpu "65816"
.segment "CODE"
.org $C220
map_control_0ec220:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $2E ; distance low bit/count
