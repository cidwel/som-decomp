.setcpu "65816"
.segment "CODE"
.org $7239
map_control_0e7239:
    .byte $E1 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $E3 ; previous-row copy count
