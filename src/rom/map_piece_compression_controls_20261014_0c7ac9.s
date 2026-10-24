.setcpu "65816"
.segment "CODE"
.org $7AC9
map_control_0c7ac9:
    .byte $ED ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
