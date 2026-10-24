.setcpu "65816"
.segment "CODE"
.org $31FA
map_control_0d31fa:
    .byte $EB ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $BE ; row-distance/count
    .byte $E1 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $90 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $8B ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
