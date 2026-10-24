.setcpu "65816"
.segment "CODE"
.org $31DC
map_control_0d31dc:
    .byte $EB ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $BE ; row-distance/count
    .byte $E1 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $AC ; row-distance/count
