.setcpu "65816"
.segment "CODE"
.org $1B7E
map_control_0e1b7e:
    .byte $E3 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
