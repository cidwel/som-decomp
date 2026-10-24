.setcpu "65816"
.segment "CODE"
.org $C048
map_control_0ec048:
    .byte $ED ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
