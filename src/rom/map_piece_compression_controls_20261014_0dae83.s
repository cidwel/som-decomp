.setcpu "65816"
.segment "CODE"
.org $AE83
map_control_0dae83:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $98 ; row-distance/count
    .byte $E1 ; previous-row copy count
