.setcpu "65816"
.segment "CODE"
.org $091C
map_control_0e091c:
    .byte $ED ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $0A ; distance low bit/count
