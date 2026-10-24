.setcpu "65816"
.segment "CODE"
.org $011E
map_control_0f011e:
    .byte $E3 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $9F ; row-distance/count
