.setcpu "65816"
.segment "CODE"
.org $00A3
map_control_0f00a3:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $E4 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
