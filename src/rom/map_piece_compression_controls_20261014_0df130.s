.setcpu "65816"
.segment "CODE"
.org $F130
map_control_0df130:
    .byte $E1 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
