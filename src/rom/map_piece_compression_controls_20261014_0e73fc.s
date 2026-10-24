.setcpu "65816"
.segment "CODE"
.org $73FC
map_control_0e73fc:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $9C ; row-distance/count
    .byte $E1 ; previous-row copy count
