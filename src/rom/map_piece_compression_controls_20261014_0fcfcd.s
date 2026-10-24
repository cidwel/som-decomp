.setcpu "65816"
.segment "CODE"
.org $CFCD
map_control_0fcfcd:
    .byte $ED ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
