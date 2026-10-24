.setcpu "65816"
.segment "CODE"
.org $9EC9
map_control_0e9ec9:
    .byte $E7 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
