.setcpu "65816"
.segment "CODE"
.org $7FE7
map_control_0c7fe7:
    .byte $ED ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
