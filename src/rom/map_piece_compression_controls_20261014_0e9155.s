.setcpu "65816"
.segment "CODE"
.org $9155
map_control_0e9155:
    .byte $ED ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
