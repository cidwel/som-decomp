.setcpu "65816"
.segment "CODE"
.org $7458
map_control_0e7458:
    .byte $E0 ; previous-row copy escape
    .byte $9C ; row-distance/count
    .byte $E1 ; previous-row copy count
