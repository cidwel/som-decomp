.setcpu "65816"
.segment "CODE"
.org $62D9
map_control_0e62d9:
    .byte $ED ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
