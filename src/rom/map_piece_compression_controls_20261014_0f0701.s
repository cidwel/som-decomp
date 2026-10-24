.setcpu "65816"
.segment "CODE"
.org $0701
map_control_0f0701:
    .byte $E0 ; previous-row copy escape
    .byte $D9 ; row-distance/count
    .byte $E2 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $AE ; row-distance/count
