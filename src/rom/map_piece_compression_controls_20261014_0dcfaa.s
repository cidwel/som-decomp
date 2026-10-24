.setcpu "65816"
.segment "CODE"
.org $CFAA
map_control_0dcfaa:
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
